//uri:	https://leetcode.com/problems/powx-n/

/*
 *	pow(x, n)可以采用递归方式求解，每次减半，最终减为0.由于n可能为负数，
 *	所以要稍微注意一下。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
 * */

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        
        double c = pow(x, n / 2);
        c *= c;
        if(n % 2 == 1) c *= x;
        if(n % 2 == -1) c /= x;
        
        return c;
    }
};
