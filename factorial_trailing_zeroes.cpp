//uri:	https://leetcode.com/problems/factorial-trailing-zeroes/

/*
 *	阶乘尾数0的个数与5有关，所以，查找5个个数就好，但是有些数字例如25会包含两个
 *	数字5，所以能被5除两次。
 *	空间复杂度：O(1).
 *	时间复杂度：O(log5(n)).
 * */

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n /= 5) {
            cnt += n;
        }
        
        return cnt;
    }
};
