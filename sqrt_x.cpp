//uri:	https://leetcode.com/problems/sqrtx/

/*
 *	求非负整数的平方根可以采用二分查找的方式。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int mySqrt(int x) {
        long left = 0;
        long right = x;
        long mid = 0;
        int y = 0;
        
        while(left <= right) {
            mid = ((right - left) >> 1) + left;
            long t = mid * mid;
            
            if(t == x) return mid;
            if(t > x) right = mid - 1;
            else left = mid + 1, y = mid;
        }
        
        return y;
    }
};
