//uri:	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/*
 *	二分查找，如果left，right和mid下标处的值相同，那么，就对这个区间枚举最小值，
 *	否则继续用二分查找来做。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while ( left <= right ) {
            int mid = (left + right) >> 1;
            
            if ( nums[left] == nums[right] && nums[mid] == nums[right] ) {
                for ( int i = left + 1; i <= right; ++ i ) {
                    if ( nums[i] < nums[left] ) { return nums[i]; }
                }
                
                return nums[left];
            }
            
            if ( nums[left] >= nums[right] && nums[mid] >= nums[left] ) { left = mid + 1; }
            else { right = mid; }
        }
        
        return nums[right];
    }
};
