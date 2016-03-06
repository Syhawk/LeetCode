//uri:	https://leetcode.com/problems/fraction-to-recurring-decimal/

/*
 *	存储被除数以及出现的位置，当再次出现这个被除数时，除法运算结束，在第一个出现的
 *	位置插入左括号，在尾后插入右括号。
 *	空间复杂度：O(未知).
 *	时间复杂度：O(未知).
 * */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        long x = numerator;
        long y = denominator;
        bool flg = 0;
        
        if(x < 0) {
            x = -x;
            flg = 1 - flg;
        }
        if(y < 0) {
            y = -y;
            flg = 1 - flg;
        }
        
        string s = "";
        
        if(flg) s += '-';
        s += to_string(x / y);
        x %= y;
        if(x) s += '.';
        
        int len = s.size() - 1;
        unordered_map<long, int> digit;
        while(x) {
            if(digit.find(x) != digit.end()) {
                s.insert(digit[x], "(");
                s += ')';
                break;
            }
            digit[x] = ++ len;
            x *= 10;
            s += '0' + (x / y);
            x %= y;
        }
        
        return s;
    }
};
