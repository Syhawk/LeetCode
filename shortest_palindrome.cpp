//uri:	https://leetcode.com/problems/shortest-palindrome/

/*
 *	字符串kmp算法。将字符串s翻转之后得到新的字符串palin，然后采用kmp算法，在palin中查找s的子串，当满足条件i + j >= 字符串的长度时终止。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    string shortestPalindrome(string s) {
        string palin = "";
        vector<int> next(s.size() + 1, 0);
        
        getNextVal(s, next);
        
        for ( int i = s.size() - 1; i >= 0; -- i ) { palin += s[i]; }
        
        int i = 0, j = 0;
        int len = palin.size();
        while ( palin[i] && i + j < len ) {
            if ( j == -1 || palin[i] == s[j] ) {
                ++ i;
                ++ j;
            } else { j = next[j]; }
        }

        for ( i -= j + 1; i >= 0; -- i ) { palin += palin[i]; }
        
        return palin;
    }
    
    void getNextVal(string& s, vector<int>& next) {
        int i = 0;
        int j = -1;
        next[0] = -1;
        
        while ( s[i] ) {
            if ( j == -1 || s[i] == s[j] ) {
                i += 1;
                j += 1;
                if ( s[i] == s[j] ) { next[i] = next[j]; }
                else { next[i] = j; }
            } else { j = next[j]; }
        }
    }
};
