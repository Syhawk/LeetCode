//uri:	https://leetcode.com/problems/climbing-stairs/

/*
 *	此题可以采用dp方式解决：dp(i) = dp(i - 1) + dp(i - 2).
 *	dp(i - 1)表示前一个阶梯可以跳一步到达，dp(i - 2)表示前两个阶梯跳两步到达。
 *	为了节省空间开销，将dp(i - 2)用a代替，dp(i - 1)用b代替，依然可以实现dp。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)
            return n;
        int a = 1, b= 2;
        for(int i = 3; i <= n; ++ i) {
            int t = a + b;
            a = b;
            b = t;
        }
        
        return b;
    }
};
