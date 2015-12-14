//uri:	https://leetcode.com/problems/reverse-integer/

/*
 *	对整数进行翻转，每次模10，然后除以10。采用更大类型范围存储，最后判断
 *	是否超出原有类型范围。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int reverse(int x) {
        long y = 0;
        while(x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        
        if(y > 2147483647 || y < -2147483648)
            return 0;
        return y;
    }
};
