//uri:	https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
 *	由于存在重复的元素，所以有些情况下不能采用二分查找，但是，某些情况下还是
 *	能够使用的
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        while(left <= right) {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == target || nums[left] == target || nums[right] == target) return true;
            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
                for(int i = left + 1; i < right; ++ i)
                    if(nums[i] == target) return true;
                return false;
            }
            if(nums[mid] > nums[right]) {
                if(target > nums[left] && target < nums[mid])
                    right = mid - 1;
                else left = mid + 1;
            } else {
                if(target > nums[mid] && target < nums[right])
                    left = mid + 1;
                else right = mid - 1;
            }
        }
        
        return false;
    }
};
