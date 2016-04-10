//uri:	https://leetcode.com/problems/basic-calculator-ii/

/*
 *	一般都是采用栈来做，由于不存在括号，只有+,-,*,/，所以可以省去栈
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int calculate(string s) {
        int x = 0;
        int y = 0;
        char op1 = '+';
        char op2 = '+';
        
        for(int i = 0; s[i]; ) {
            int val = 0;
            while(s[i] && !isdigit(s[i])) { ++ i; }
            while(s[i] && isdigit(s[i])) {
                val = val * 10 + s[i] - '0';
                ++ i;
            }
            
            if(op2 == '+' || op2 == '-') {
                if(op1 == '+') { x += y; }
                else { x -= y; }
                y = val;
                op1 = op2;
            } else if(op2 == '*') { y *= val; }
            else { y /= val; }
                
            while(s[i] && s[i] == ' ') { ++ i; }
            op2 = s[i];
        }
        
        if(op1 == '+') { x += y; }
        else { x -= y; }
        
        return x;
    }
};
