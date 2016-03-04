//uri:	https://leetcode.com/problems/find-peak-element/

/*
 *	只需要找出一个满足大于临近元素的元素下标，所以可以采用二分查找的方式。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int lhs = 0, rhs = size - 1;
        int mid = (rhs + lhs) >> 1;
        while(lhs <= rhs) {
            mid = (rhs + lhs) >> 1;
            if(mid == 0) {
                if(nums[mid] > nums[mid + 1]) break;
                lhs = mid + 1;
                continue;
            }
            
            if(mid == size - 1) {
                if(nums[mid] > nums[mid - 1]) break;
                rhs = mid - 1;
                continue;
            }
            
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) break;
                
            if(nums[mid + 1] > nums[mid]) lhs = mid + 1;
            else rhs = mid - 1;
        }
        
        return mid;
    }
};
