//uri:	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/*
 *	dp问题，状态转移方程分为两部分，一个是buy表示购买股票之后的最高利润，另一个是sell表示出售该股票之后的最高利润。
 *	sell(i, j) = max(sell(i - 1, j), sell(i, j - 1), buy(i, j - 1) + prices[j]).
 *	buy = max(buy(i, j - 1), max(sell(i - 1, 0 : j - 1)) - prices[j]).
 *	sell(i - 1, 0 : j - 1)表示最多i - 1次出售从下标0到下标j - 1的股票的最高利润。
 *	注：k的值可能会很大，prices里面也会有很多没有用的股票信息，所以，可以对prices进行无用信息删减得到cut，
 *	然后k值如果大于cut的二分之一，那么就直接计算。不能开辟二维dp，只能使用一维dp，由于dp(i, j)涉及到的状态
 *	只有dp(i - 1, j)和dp(i, j - 1)，所以可以转化为一维dp。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n ^ 2).
 * */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if ( prices.size() < 2 ) { return 0; }
        
        vector<int> cut(1, prices[0]);
        for ( int i = 1; i < prices.size(); ++ i) {
            while ( i < prices.size() && prices[i] >= prices[i - 1] ) { ++ i; }
            cut.push_back(prices[i - 1]);
            while ( i < prices.size() && prices[i] <= prices[i - 1] ) { ++ i; }
            cut.push_back(prices[i - 1]);
        }
        cut.push_back(prices[prices.size() - 1]);
        
        struct Node {
            int buy;
            int sell;
            Node() : buy(0), sell(0) {}
        };
        int max_profit = 0;
        Node dp[cut.size()];
        
        if ( k >= cut.size() / 2 ) {
            for ( int i = 1; i < cut.size(); ++ i ) {
                if ( cut[i] > cut[i - 1] ) { max_profit += cut[i] - cut[i - 1]; }
            }
            
            return max_profit;
        }
        
        dp[0].buy = -cut[0];
        
        for ( int i = 0; i < k; ++ i ) {
            int sell = 0;
            for ( int j = 1; j < cut.size(); ++ j ) {
                int _sell = sell = max(sell, dp[j].sell);

                dp[j].sell = max(dp[j - 1].sell, dp[j].sell);
                dp[j].sell = max(dp[j - 1].buy + cut[j], dp[j].sell); 
                dp[j].buy = max(dp[j - 1].buy, sell - cut[j]);

                sell = _sell;
                max_profit = max(max_profit, dp[j].sell);
            }
        }
        
        return max_profit;
    }
};
