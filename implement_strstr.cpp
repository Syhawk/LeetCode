//uri:	https://leetcode.com/problems/implement-strstr/

/*
 *	在一个字符串中查找另一个字符串出现的位置可以用bf、kmp、bm、sunday等算法。
 *	本文采用bm算法。
 *	空间复杂度：O(n).
 *	时间复杂度：O(m + n).
 * */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        vector<int> mL(26, len2 + 1);
        for(int i = 0; i < len2; ++ i)
            mL[needle[i] - 'a'] = len2 - i;
        
        for(int i = 0; i <= len1 - len2; ) {
            int j = 0;
            for(; haystack[i + j] == needle[j] && needle[j]; ++ j);
            if(needle[j] == '\0') return i;
            if(i + len2 >= len1) return -1;
            i += mL[haystack[i + len2] - 'a'];
        }
        
        return -1;
    }
};
