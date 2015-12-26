//uri:	https://leetcode.com/problems/jump-game/

/*
 *	数组为非负整数，判断能不能从第一个点跳到最后一个点。
 *	注意：当前可选的跳跃点是前一次跳跃点i到跳跃之后到达的最远点j之间的任何一个点。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size(), k = 0;
        for(int i = 0; k < len && i <= k; ++ i) {
            k = max(k, nums[i] + i);
        }
        
        return k >= len - 1;
    }
};
