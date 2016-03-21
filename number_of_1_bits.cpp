//uri:	https://leetcode.com/problems/number-of-1-bits/

/*
 *	直接统计一个数字转换为二进制后的1的个数。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            if(n & 1) cnt += 1;
            n >>= 1;
        }
        
        return cnt;
    }
};
