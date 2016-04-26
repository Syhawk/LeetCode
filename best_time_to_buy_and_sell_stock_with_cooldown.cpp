//uri:	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*
 *	动态规划：buy表示当前买入之后的结果，sell表示当前卖出之后的结果，cooldown表示至少卖出一天后的结果
 *	dp[i].buy = max(dp[i - 1].cooldown - prices[i - 1], dp[i - 1].buy);
 *	dp[i].sell = dp[i - 1].buy + prices[i - 1];
 *	dp[i].cooldown = max(dp[i - 1].cooldown, dp[i - 1].sell);
 *	由于需要买进之后才能卖出，所以，第一天不能卖出；第一天之前没有买入，所以第一天的买入不能由前一天来影响。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        class Node {
        public:
            long buy;
            long sell;
            long cooldown;
            Node(long a) : buy(a), sell(a), cooldown(a) {}
        };
        
        int len = prices.size();
        vector<Node> dp(len + 1, Node(0));
        dp[0].buy -= 0xffffffff;
        
        for ( int i = 1; i <= len; ++ i ) {
            dp[i].buy = max(dp[i - 1].cooldown - prices[i - 1], dp[i - 1].buy);
            if ( i > 1 ) { dp[i].sell = dp[i - 1].buy + prices[i - 1]; }
            dp[i].cooldown = max(dp[i - 1].cooldown, dp[i - 1].sell);
        }
        
        return max(dp[len].cooldown, dp[len].sell);
    }
};
