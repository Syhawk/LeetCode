//uri:	https://leetcode.com/problems/power-of-four/

/*
 *	首先判断是不是2的幂次方，由于4的幂次方与2的幂次方的区别在于转化为二进制数之后，4的幂次方都是在偶数位，而2的幂次方偶数位与奇数位均存在，
 *	所以可以利用这个条件进行筛选4的幂次方。
 *	空间复杂度：O(1)
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num - (num & (~num + 1))) == 0 && (num & 0x55555555);
    }
};
