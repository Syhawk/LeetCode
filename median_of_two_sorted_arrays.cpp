//uri:	https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
 *	采用二分查找的方式来做，假设nums1长度为len1，初始位置为l1，nums2长度为len2，
 *	初始位置为l2，那么，中位数为mid = (len1 + len2 + 1) / 2，如果len1 + len2为
 *	偶数还需要查找mid位置的下一个元素，方法与查找mid位置相同。根据nums1和nums2
 *	的长度，nums1始终表示len - l长度较短的那一个，否则就与nums2交换数据。将mid
 *	分为两部分，一部分为mid / 2，一部分为mid - mid / 2。因为nums1长度较短，所以
 *	nums1每次查找元素都查找min(len1, l1 + mid / 2)的位置，在nums2则查找剩下的
 *	l2 +　mid - mid / 2的位置，然后比较大小，舍弃元素值较小的那一部分，更新mid,
 *	以及其他变量，以此循环下去，直至mid为1或者l1 == len1，或者
 *	nums1[l1 + mid / 2 - 1] == nums2[l2 + mid - 1 - mid / 2]结束。
 *	空间复杂度：O(1).
 *	时间复杂度：O(log(m + n)).
 * */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int l1 = 0, l2 = 0;
        int mid = (len1 + len2 + 1) >> 1;
        
        while(1) {
            if(len1 - l1 > len2 - l2) {
               swap(nums1, nums2);
               swap(len1, len2);
               swap(l1, l2);
            }
            
            if(len1 == l1) { return ((len1 + len2) & 0x1) ? nums2[l2 + mid - 1] : (nums2[l2 + mid] + nums2[l2 + mid - 1]) / 2.0; }
            if(mid == 1) {
                int v = min(nums1[l1], nums2[l2]);
                if(((len1 + len2) & 0x1)) return v;
                
                if(v == nums1[l1]) { return (v + min(getMin(nums1, l1 + 1, len1), nums2[l2])) / 2.0; }
                return (v + min(getMin(nums2, l2 + 1, len2), nums1[l1])) / 2.0;
        	}
            
            int k = min(mid >> 1, len1 - l1);
            int mid1 = l1 + k;
            int mid2 = l2 + mid - k;
            
            if(nums1[mid1 - 1] < nums2[mid2 - 1]) {
               mid -= k;
               l1 = mid1;
            } else if(nums1[mid1 - 1] > nums2[mid2 - 1]) {
               mid = k;
               l2 = mid2;
            } else {
               return ((len1 + len2) & 0x1) ? nums1[mid1 - 1]
               : (nums1[mid1 - 1] + min(getMin(nums1, mid1, len1), getMin(nums2, mid2, len2)) ) / 2.0;
            }
        }

        return 0;
    }
    
    int getMin(vector<int>& nums, int l, int len) {
        if(l < len) { return nums[l]; }
        return 0x7fffffff;
    }
};
