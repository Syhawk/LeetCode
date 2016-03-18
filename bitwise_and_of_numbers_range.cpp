//uri:	https://leetcode.com/problems/bitwise-and-of-numbers-range/

/*
 *	对于将区间[m, n]转换成二进制的每一位，判断包含此位的最大值是否>= n，从而决定，
 *	对于[m, n]之间的所有元素均包含该位。
 *	空间复杂度：O(1).
 *	时间复杂度：O(log2(m)).
 * */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        
        int r = 0;
        int bit = 1;
        int p = m;
        
        while(p) {
            if(m & bit) {
                if(n <= (m ^ (bit - 1))) r += bit;
                m = m & (m - 1);
            }
            
            p >>= 1;
            bit <<= 1;
        }
        
        return r;
    }
};
