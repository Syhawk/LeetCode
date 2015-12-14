//uri:	https://leetcode.com/problems/palindrome-number/

/*
 *	判断是否为负数，如果为负数，那就不是回文数字。
 *	转化为字符串，然后进行判断。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        string s = to_string(x);
        int len = s.size();
        for(int i = 0; i <= len / 2; ++ i) {
            if(s[i] != s[len - i - 1])
                return false;
        }
        
        return true;
    }
};
