//uri:	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
 *	购买一次，出售一次，我们把prices数组转化一下，prices[i] -= prices[i - 1].
 *	从第二个元素开始，相当于求该数组的最大连续和。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mp = 0;
        int sum = 0;
        for(int i = 1; i < len; ++ i) {
            int x = prices[i] - prices[i - 1];
            if(sum <= 0) sum = x;
            else sum += x;
            
            mp = max(sum, mp);
        }
        
        return mp;
    }
};
