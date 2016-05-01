//uri:	https://leetcode.com/problems/coin-change/

/*
 *	dp问题，状态转移方程：dp(j) = min(dp(j), dp(j - coins[i]) + 1);
 *	该状态转移方程表示当前状态由上一状态再加一个硬币值得到。
 *	空间复杂度：O(m).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> nums(amount + 1, 0x7ffffff);
        nums[0] = 0;
        
        for ( int i = 0; i < coins.size(); ++ i ) {
            int step = coins[i];
            for ( int j = step; j <= amount; ++ j ) { nums[j] = min(nums[j], nums[j - step] + 1); }
        }
        
        return nums[amount] == 0x7ffffff ? -1 : nums[amount];
    }
};
