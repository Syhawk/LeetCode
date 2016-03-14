//uri:	https://leetcode.com/problems/rotate-array/

/*
 *	首先翻转整个数组，然后翻转前K个数，最后翻转剩下的数。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        swapArray(nums, 0, len - 1);
        swapArray(nums, 0, k - 1);
        swapArray(nums, k, len - 1);
    }
    
    void swapArray(vector<int>& nums, int lhs, int rhs) {
        for( ; lhs < rhs; ++ lhs, -- rhs)
            swap(nums[lhs], nums[rhs]);
    }
};
