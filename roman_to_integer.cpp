//uri:	https://leetcode.com/problems/roman-to-integer/

/*
 *	罗马数字转换为整数与整数转换为罗马数字相同。
 *	从最高位起进行判断，对数字4、9进行特殊处理，其他数字按照代表符号相加即可。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int romanToInt(string s) {
        int r = 0, i = 0;
        r += change(s, i, 1000, 'M');
        r += change(s, i, 100, 'C', 'D', 'M');
        r += change(s, i, 10, 'X', 'L', 'C');
        r += change(s, i, 1, 'I', 'V', 'X');
        
        return r;
    }
    
    int change(string &s, int &i, int val, char lhs, char mhs = '\0', char rhs = '\0') {
        int x = 0;
        if(s[i] && s[i + 1] && s[i] == lhs && s[i + 1] == mhs) {
            x += 4 * val, i += 2;
        }
        if(s[i] && s[i + 1] && s[i] == lhs && s[i + 1] == rhs) {
            x += 9 * val, i += 2;
        }
        
        for( ; s[i]; ++ i) {
            if(s[i] == lhs)
                x += val;
            else if(s[i] == mhs)
                x += 5 * val;
            else if(s[i] == rhs)
                x += 10 * val;
            else break;
        }
        
        return x;
    }
};
