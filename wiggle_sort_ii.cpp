//uri:	https://leetcode.com/problems/wiggle-sort-ii/

/*	
 *	方法一：直接采用快排
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
 *	方法二：查找中位数，然后采用threeWayPartition进行元素分类，其中需要坐标转换。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 *	注：实际时耗方法一要比方法二少。
 * */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size() - 1;
        vector<int> tmp(len + 1, 0);
        
        for ( int i = 1; i < nums.size(); i += 2) { tmp[i] = nums[len --]; }
        for ( int i = 0; i < nums.size(); i += 2) { tmp[i] = nums[len --]; }
        
        swap(nums, tmp);
        
        //int mid = find_nth_number(nums, nums.size() / 2);
        
        //threeWayPartition(nums, mid);
    }
    
    void threeWayPartition(vector<int>& nums, int mid) {
        int len = nums.size() | 1;
        #define A(i)  nums[(2 * (i) + 1) % len]
        int lower = 0;
        int upper = nums.size() - 1;
        int equal = 0;
        
        while ( equal <= upper ) {
            if ( A(equal) < mid ) { swap(A(equal), A(upper --)); }
            else if ( A(equal) > mid ) { swap(A(equal ++), A(lower ++)); }
            else { equal += 1; }
        }
    }
    
    int find_nth_number(vector<int>& nums, int nth) {
        swap(nums[0], nums[rand() % nums.size()]);
        
        int lhs = 0;
        int rhs = nums.size() - 1;
        
        while ( true ) {
            int left = lhs;
            int right = rhs;
            int val = nums[left];
            
            while ( left < right ) {
                while ( left < right && nums[left] < val ) { left += 1; }
                while ( left < right && nums[right] >= val ) { right -= 1; }
                swap(nums[left], nums[right]);
            }
            
            if ( left == nth ) { return val; }
            if ( left < nth ) { lhs = left + 1; }
            else { rhs = left - 1; }
        }
        
        return 0;
    }
};
