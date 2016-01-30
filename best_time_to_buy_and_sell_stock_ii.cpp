//uri:	https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
 *	把今天与前一天的利润算出来，把所有正的利润加起来就是最大利润。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mp = 0;
        for(int i = 1; i < len; ++ i) {
            int x = prices[i] - prices[i - 1];
            if(x > 0) mp += x;
        }
        
        return mp;
    }
};
