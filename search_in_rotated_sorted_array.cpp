//uri:	https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
 *	由于不存在相同的数字，所以可以采用二分查找的方式。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        
        while(lhs <= rhs) {
            int mid = (lhs + rhs) >> 1;
            if(nums[mid] == target) { return mid; }
            
            if(nums[lhs] > nums[rhs]) {
                if(nums[mid] >= nums[lhs]) {
                    if(target >= nums[lhs] && target <= nums[mid]) { rhs = mid - 1; }
                    else { lhs = mid + 1; }
                } else {
                    if(target >= nums[mid] && target <= nums[rhs]) { lhs = mid + 1; }
                    else { rhs = mid - 1; }
                }
            } else {
                if(nums[mid] > target) { rhs = mid - 1; }
                else { lhs = mid + 1; }
            }
        }
        
        return -1;
    }
};
