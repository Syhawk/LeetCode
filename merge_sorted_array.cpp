//uri:	https://leetcode.com/problems/merge-sorted-array/

/*
 *	nums1有足够的空间，所以先将nums1中的元素右移n个位置，然后比较选取两个较小的
 *	元素放在nums1的头部，依次循环
 *	空间复杂度：O(1)
 *	时间复杂度：O(m+n)
 * */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        for(int i = len - 1, j = m - 1; j >= 0; -- i, -- j)
            nums1[i] = nums1[j];
            
        for(int i = 0, j = len -m, k = 0; i < len; ++ i) {
            if(k >= n && j < len) nums1[i] = nums1[j ++];
            else if(j >= len && k < n) nums1[i] = nums2[k ++];
            else if(k < n && j < len) {
                if(nums1[j] <= nums2[k])
                    nums1[i] = nums1[j ++];
                else nums1[i] = nums2[k ++];
            }
        }
    }
};
