//uri:	https://leetcode.com/problems/search-insert-position/

/*
 *	查找目标值在nums数组中插入的位置。事实上就是查找nums中第一个大于等于target的
 *	值的下标，也就是相当于实现lower_bound函数。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        if(target > nums[rhs]) return rhs + 1;
        if(target < nums[0]) return 0;
        int mid = 0;
        while(lhs < rhs) {
            mid = ((rhs - lhs) >> 1) + lhs;
            if(nums[mid] >= target) rhs = mid;
            else lhs = mid + 1;
        }
        
        return lhs;
    }
};
