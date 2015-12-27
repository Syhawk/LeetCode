//uri:	https://leetcode.com/problems/length-of-last-word/

/*
 *	首先省略从尾部起的所有空格字符，然后计算有多少个连续的字母字符。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size() - 1;
        while(size >= 0 && s[size] == ' ')
            -- size;
        int index = size;
        while(size >= 0 && isalpha(s[size]))
            -- size;
        
        return index - size;
    }
};
