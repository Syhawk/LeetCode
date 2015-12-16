//uri:	https://leetcode.com/problems/count-and-say/

/*
 *	规则如题目所述，统计有多少个连续相同的数字，然后把数字个数与该数字组合在一块
 *	，构成一个字符串，依次迭代。可以采用打表的方式。
 *	空间复杂度：O(未知).
 *	时间复杂度：O(未知).
 *	注：n为48，时耗约为4.2秒，64则超时。空间复杂度为时间复杂度的平方根。
 * */

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n < 2) return s;
        string str = "";
        for(int i = 1; i < n; ++ i) {
            char ch = s[0];
            int cnt = 1;
            for(int j = 1; s[j]; ++ j) {
                if(s[j] == ch) ++ cnt;
                else {
                    str += to_string(cnt) + ch;
                    ch = s[j];
                    cnt = 1;
                }
            }
            
            str += to_string(cnt) + ch;
            s = str;
            str = "";
        }
        
        return s;
    }
};
