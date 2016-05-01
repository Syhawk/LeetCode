//uri:	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
 *	dp问题，状态转移方程为：maxProfit = max(maxProfit, dp[0, i], dp[i + 1, length - 1])
 *	maxProfit为最大利润，dp[i, j]表示区间[i, j]的最大利润。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if ( N < 2 ) {  return 0; }
        
        vector<int> dp(N, 0);
        int maxPro = 0;
        int _min = prices[0];
        for ( int i = 1; i < N; ++ i ) {
            dp[i] = max(dp[i - 1], prices[i] - _min);
            _min = min(_min, prices[i]);
            maxPro = max(maxPro, dp[i]);
        }
        
        int _max = prices[N - 1];
        dp[N - 1] = 0;
        for ( int i = N - 2; i >= 0; -- i ) {
            dp[i] = max(_max - prices[i], dp[i + 1]);
            _max = max(_max, prices[i]);
            if ( i ) { maxPro = max(maxPro, dp[i] + dp[i - 1]); }
        }
        
        return maxPro;
    }
};
