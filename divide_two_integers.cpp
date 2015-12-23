//uri:	https://leetcode.com/problems/divide-two-integers/

/*
 *	由于不允许使用乘、除以及取余运算，所以可以采用加、减以及位运算来实现除法。
 *	首先考虑特殊情况，主要是int整数越界情况。然后将被除数与除数转化为正整数，
 *	对正整数进行操作。由于所有的int整数都可以转化成二进制来表示，那么一个
 *	十进制整数x可以由另一个十进制整数y以及余数z来表示。
 *	x = (2 ^ a1 + 2 ^ a2 + 2 ^ a3 + ... 2 ^ an) * y + z。其中ai均为非负整数，
 *	且ai < 32, ai < ai+1
 *	那么，我们可以先找出最大的an，循环从an到a1，然后将2 ^ ai叠加起来就是商。
 *	最大an就是被除数与除数转化为二进制之后的位数之差，也就是代码中cnt1与cnt2之差。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int divide(int dividend, int divisor) {
        int MAX_INF = 0x7fffffff;
        int MIN_INF = 0x80000000;
        if(divisor == 0) return MAX_INF;
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend == MIN_INF) return MAX_INF;
            else return -dividend;
        }
        if(dividend == divisor) return 1;
        if(divisor == MIN_INF) return 0;
        
        bool flg = 0;
        if((dividend ^ divisor) < 0) flg = 1;
        int x = dividend, y = 0, z = abs(divisor);
        if(dividend == MIN_INF) {
            x = MAX_INF;
            y = 1;
        } else if(dividend < 0)
            x = -dividend;
        
        int t1 = x, t2 = z;
        int cnt1 = 0, cnt2 = 0;
        while(t1) {
            t1 >>= 1;
            ++ cnt1;
        }
        while(t2) {
            t2 >>= 1;
            ++ cnt2;
        }
        if(cnt1 < cnt2) return 0;
        
        int cnt = 0;
        
        if(x - (z - y) >= 0) {
            x -= (z - y);
            ++ cnt;
            y = 0;
        } else return 0;
        cnt1 -= cnt2;
        while(cnt1 >= 0) {
            int t = z << cnt1;
            if(x - t >= 0) {
                x -= t;
                cnt += (1 << cnt1);
            }
            -- cnt1;
        }
        
        if(flg) cnt = -cnt;
        return cnt;
    }
};
