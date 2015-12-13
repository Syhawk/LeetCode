//uri:	https://leetcode.com/submissions/detail/46622061/

/*
 *	根据numRows大小，创建numRows个字符串，分别代表每一行所包含的字符串，
 *	最后将这numRows个字符串合并。for遍历一次字符串s，把s中的字符分配到
 *	对应的行所表示的字符串中。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string str[numRows] = {};
        int j = 0;
        int k = numRows * 2 - 2;
        for(int i = 0; s[i]; ++ i) {
            int t = min(j, k);
            str[t] += s[i];
            ++ j;
            -- k;
            if(k == 0) {
                j = 0;
                k = numRows * 2 - 2;
            }
        }
        
        s = "";
        for(int i = 0; i < numRows; ++ i)
            s += str[i];
        
        return s;
    }
};
