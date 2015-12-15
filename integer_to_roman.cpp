//uri:	https://leetcode.com/problems/integer-to-roman/

/*
 *	整数转化为罗马数字，个位、十位、百位与千位转换方式均相同。
 *	以个位为例：1-3都是'I'的个数，4是'IX',5-8都是'V' + 该数字减去5后
 *	再表示'I'的个数，9是'IX'来表示。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int unit = num % 10;
        num /= 10;
        int ten = num % 10;
        num /= 10;
        
        change(s, num / 10, 'M');
        change(s, num % 10, 'C', 'D', 'M');
        change(s, ten, 'X', 'L', 'C');
        change(s, unit, 'I', 'V', 'X');
        
        return s;
    }
    
    void change(string &s, int digit, char lhs, char mhs = '\0', char rhs = '\0') {
        if(digit == 9) {
            s += lhs;
            s += rhs;
        }
        else if(digit == 4) {
            s += lhs;
            s += mhs;
        } else {
            if(digit > 4) {
                digit -= 5;
                s += mhs;
            }
            while(digit --) {
                s += lhs;
            }
        }
    }
};
