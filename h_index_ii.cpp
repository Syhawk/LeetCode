//uri:	https://leetcode.com/problems/h-index-ii/

/*
 *	对一个非递减非负数组，找出第一个元素值满足该元素值>=该元素值以后的元素个数。
 *	采用二分查找方式解决。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int right = citations.size() - 1;
        if(right == -1) return 0;
        if(citations[right] == 0) return 0;
        
        int len = right + 1;
        int left = 0, mid = 0;
        while(left <= right) {
            mid = ((right - left) >> 1) + left;
            
            if(citations[mid] == 0) left = mid + 1;
            else if(citations[mid] < len - mid) left = mid + 1;
            else right = mid;
            
            if(left == right && mid == left) break;
        }
        
        return len - mid;
    }
};
