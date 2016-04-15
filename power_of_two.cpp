//uri:	https://leetcode.com/problems/power-of-two/

/*
 *	每次整除2判断。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) { return true; }
        if (n < 1) { return false; }
        while (n != 1) {
            if (n % 2 == 1) { return false; }
            n >>= 1;
        }
        
        return true;
    }
};
