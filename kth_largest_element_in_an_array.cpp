//uri:	https://leetcode.com/problems/kth-largest-element-in-an-array/

/*
 *	借助于快排算法的partition函数，通过改写其中的部分，按照降序排序的方式。
 *	空间复杂度：O(1).
 *	时间复杂度：O(nlog(n)).
 * */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int rhs = nums.size() - 1;
        int lhs = 0;
        while(lhs < rhs) {
            int l = lhs;
            int r = rhs;
            int key = nums[l];
            while(l < r) {
                while(l <= r && nums[r] <= key) -- r;
                nums[l] = nums[r];
                while(l < r && nums[l] > key) ++ l;
                nums[r] = nums[l];
            }
            nums[l] = key;
            
            if(k == l + 1) { return key; }
            if(k < l + 1) rhs = l - 1;
            else lhs = l + 1;
        }
        
        return nums[lhs];
    }
};
