//uri:  https://leetcode.com/problems/search-for-a-range/

/*
 *	实际上是编写二分查找的lower_bound和upper_bound函数
 * */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lhs = 0, rhs = nums.size() - 1;
        int mid = ((rhs - lhs) >> 1) + lhs;
        while(lhs < rhs) {
            mid = ((rhs - lhs) >> 1) + lhs;
            if(nums[mid] < target) lhs = mid + 1;
            else rhs = mid;
        }
        
        if(nums[rhs] != target)  return {-1, -1};
        
        int l = rhs;
        rhs = nums.size() - 1;
        mid = ((rhs - lhs) >> 1) + lhs;
        while(lhs < rhs) {
            mid = ((rhs - lhs) >> 1) + lhs;
            if(nums[mid] <= target) lhs = mid + 1;
            else rhs = mid;
        }
        
        if(nums[lhs] > target) -- lhs;
        
        return {l, lhs};
    }
};
