//uri:	https://leetcode.com/problems/happy-number/

/*
 *	经过推算，在演化过程中，出现的数值小于10时，这个数值为1或者7，才可以判定为
 *	happy number。
 *	空间复杂度：O(1).
 *	时间复杂度：O(未知).
 * */

class Solution {
public:
    bool isHappy(int n) {
        while(1) {
            if(n < 10) {
                if(n == 1 || n == 7) return true;
                else return false;
            }
            
            int sum = 0;
            while(n) {
                int t = n % 10;
                sum += t * t;
                n /= 10;
            }
            n = sum;
        }
        
        return true;
    }
};
