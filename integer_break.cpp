//uri:	https://leetcode.com/problems/integer-break/

/*
 *	将n尽可能拆分成3，如果有余数为1，那就拆分成两个2.
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    int integerBreak(int n) {
        if ( n <= 3 ) { return n - 1; }
        int cnt = n / 3;
        int least = n % 3;
        int sum = 1;
        if ( least == 1 ) {
            least = 4;
            cnt -= 1;
        }
        
        for ( int i = 0; i < cnt; ++ i ) { sum *= 3; }
        if ( least ) { sum *= least; }
        
        return sum;
    }
};
