//uri:	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
 *	由于不存在重复的数字，所以可以采用二分查找的方式查找最小的数字。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int rhs = nums.size() - 1, lhs = 0;
        
        while(lhs <= rhs) {
            if(lhs == rhs) return nums[lhs];
            
            int mid = (rhs + lhs) >> 1;
            if(nums[rhs] > nums[lhs]) {
                return nums[lhs];
            } else {
                if(nums[mid] >= nums[lhs])
                    lhs = mid + 1;
                else rhs = mid;
            }
        }
        
        return -1;
    }
};
