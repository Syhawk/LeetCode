//uri:	https://leetcode.com/problems/valid-palindrome/

/*
 *	用两个下标分别从字符串头部和尾部进行比对。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j;) {
            if(!isalpha(s[i])) ++ i;
            if(!isalpha(s[j])) -- j;
            if(i < j && isalpha(s[i]) && isalpha(s[j])) {
                if(tolower(s[i]) != tolower(s[j])) return false;
                ++ i;
                -- j;
            }
        }
        
        return true;
    }
};
