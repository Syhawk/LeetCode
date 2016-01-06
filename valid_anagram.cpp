//uri:	https://leetcode.com/problems/valid-anagram/

/*
 *	判断两个字符串包含的字符种类以及数目是否相同。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len = s.size();
        if(len != t.size()) return false;
        
        int num[26] = {};
        for(int i = 0; i < len; ++ i) {
            num[s[i] - 'a'] += 1;
            num[t[i] - 'a'] -= 1;
        }
        
        for(int i = 0; i < 26; ++ i)
            if(num[i]) return false;
            
        return true;
    }
};
