//uri:	https://leetcode.com/problems/string-to-integer-atoi/

/*
 *	string to integer情况比较多，并不是规范的整数转化为字符串所得到的结果。
 *	情况一：整数开始之前存在空格。（解决方法：全部剔除掉）
 *	情况二：字符串在数字字符开始之前存在'-'、'+'或者其他字符。
 *	（解决方法：记录当前一个字符）。
 *	情况三：记录从情况二开始后面最多十一个字符，不是数字字符就终止记录。
 *	情况四：根据情况二和情况三判断是否能够转化为整型，如果能救转化。
 *	情况五：判断转化结果是否超出了整型范围。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int myAtoi(string str) {
        int k = 0;
        string s = "";
        int len = str.size();
        for(; str[k] && str[k] == ' '; ++ k);
        if(str[k] == '+' || str[k] == '-')
            s += str[k++];
        for(int i = 0;  k + i < len && i < 10 && isdigit(str[k + i]); ++ i)
            s += str[k + i];
        
        int flg = 0;
        bool digit = false;
        for(int i = 0; s[i]; ++ i) {
            if(!isdigit(s[i])) {
                if(s[i] != '-' && s[i] != '+')
                    return 0;
                ++ flg;
            } else
                flg = 0, digit = true;
            
            if(digit && flg) return 0;
            if(flg >= 2) return 0;
        }
        
        if(!digit) return 0;
        if(s.size() > 11 && s[0] != '-')
            return 2147483647;
        if(s.size() > 11 && s[0] == '-')
            return -2147483648;
        
        long long r = stoll(s);
        if(r > 2147483647LL)
            return 2147483647;
        if(r < -2147483648LL)
            return -2147483648;
            
        return r;
    }
};
