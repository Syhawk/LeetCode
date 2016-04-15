//uri:	https://leetcode.com/problems/jump-game-ii/

/*
 *	贪心。从i到达下标j所需要的最少的步数是第一次到达j的步数，以后的每次到达步数一定会>=第一次到达的步数，所以，我们只需要判断当前
 *	steps(nums[i]) + 1所表示的步数是否要比steps(j)小，如果小就更新，否则不更新。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0x7fffffff);
        dp[0] = 0;
        
        for (int i = 0; i < len; ++ i) {
            for (int j = min(i + nums[i], len - 1); j > i && dp[j] > dp[i] + 1; -- j) { dp[j] = dp[i] + 1; }
        }
        
        return dp[len - 1];
    }
};
