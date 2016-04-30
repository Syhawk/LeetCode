//uri:	https://leetcode.com/problems/bulb-switcher/

/*
 *	这个题目有规律，如果我们测试数据是从0~100，那么得到的结果就是0,1,1,1,3,3,3,3,3,7,7,7,7,7,7,7……
 *	除了0得到零以外，剩下的都是奇数个'on'状态，而且这个状态的数值是递增2的，状态的数目也是递增2的。
 *	通过以上规律得到的数列，就可以建立相应的方程，然后调整小数数值取整方向进行求解
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int bulbSwitch(int n) {
        double c = sqrt(n + 1.0) - 0.5;
        if ( c > int(c) + 0.5 ) { return ceil(c); }
        return c;
    }
};
