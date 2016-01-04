//uri:	https://leetcode.com/problems/ugly-number/

/*
 *	由于一个数x = 2^a * 3^b * 5^c,而且a + b + c >= 1,所以非正数要特殊处理。
 *	然后将这个数的2、3、5分别除尽，判断最后得到的数是否为1就能判断这个数x是否为
 *	ugly number。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;

        while(num % 2 == 0)
            num /= 2;
        while(num % 3 == 0)
            num /= 3;
        while(num % 5 == 0)
            num /= 5;

        if(num == 1) return true;
        return false;
    }
};
