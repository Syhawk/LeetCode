//uri:	https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
 *	最长不重复字符子串：从字符串头部开始循环，只要不出现重复字符，
 *	那么，不重复字符子串会一直增加。如果遇到重复字符，那么，就要从中选择
 *	是出现该重复字符之前的子串还是出现重复字符之后的子串作为最长子串。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flg[128] = {};
        int lhs = -1;
        int maxLength = 0;
        for(int i = 0; s[i]; ++ i) {
            int ch = s[i];
            if(flg[ch]) {
                lhs = max(flg[ch] - 1, lhs);
            }
            maxLength = max(maxLength, i - lhs);
            flg[ch] = i + 1;
        }
        
        return maxLength;
    }
    
};
