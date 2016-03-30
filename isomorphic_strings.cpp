//uri:	https://leetcode.com/problems/isomorphic-strings/

/*
 *	对字符实现一一映射，那么采用两个字符vector把一一映射存储起来，然后对比。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        vector<char> stot(127, 0);
        vector<char> ttos(127, 0);
        for(int i = 0; s[i]; ++ i) {
            if(stot[s[i]] == 0 && ttos[t[i]] == 0) {
                stot[s[i]] = t[i];
                ttos[t[i]] = s[i];
            }
            else if(stot[s[i]] == t[i] && ttos[t[i]] == s[i]) { continue; }
            else { return false; }
        }
        
        return true;
    }
};
