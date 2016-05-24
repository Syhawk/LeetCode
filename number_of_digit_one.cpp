//uri:	https://leetcode.com/problems/number-of-digit-one/

/*
 *	对于每一个数值，按照十进制数的基数进行计算，然后最后合并起来，比如说，57，可以拆分成计算50含有多少个1. 7含有多少个1，然后这两部分求和。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int countDigitOne(int n) {
        if ( n < 1 ) { return 0; }
        
        int cnt = 0;
        for (int i = 0, base = 1, pre = 0; n; n /= 10, base *= 10, ++ i ) {
            int t = n % 10;
            if ( t ) { cnt += t * (base / 10) * i; }
            if ( t ) { cnt += (t == 1) ? pre + 1 : base; }
            
            pre += t * base;
        }
        
        return cnt;
    }
};
