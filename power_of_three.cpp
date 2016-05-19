//uri:	https://leetcode.com/problems/power-of-three/

/*
 *	假设一个数是3的幂次方，那么这个数一定能整除3的最大的幂次方。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
