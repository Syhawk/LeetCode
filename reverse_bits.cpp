//uri:	https://leetcode.com/problems/reverse-bits/

/*
 *	循环次数一定要为32次，而不是根据n是否非零来判断。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        for(int i = 0; i < 32; ++ i) {
            r = (r << 1) + (n & 1);
            n >>= 1;
        }
        
        return r;
    }
};
