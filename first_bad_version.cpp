//uri:	https://leetcode.com/problems/first-bad-version/

/*
 *	出现一个badversion后，其后面的version都是bad的，所以可以采用二分查找。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid = 1;
        while(left <= right) {
            mid = ((right - left) >> 1) + left;
            
            if(isBadVersion(mid)) right = mid;
            else left = mid + 1;
            
            if(mid == left && mid == right) break;
        }
        
        return mid;
    }
};
