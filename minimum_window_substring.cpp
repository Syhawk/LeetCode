//uri:	https://leetcode.com/problems/minimum-window-substring/

/*
 *	区间[j, i]表示从下标j到下标i正好满足字符串t的条件，然后i右移，直至下标j所表示的字符数量增加，
 *	j右移，找到满足字符串t的条件另一组情况。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    string minWindow(string s, string t) {
        const int N = 128;
        int cnt = t.size();
        vector<int> t_cnt(N, 0);
        vector<int> vis(N, 0);
        int min_window_index = 0;
        int min_window_length = 0x7fffffff;
        
        for ( int i = 0; t[i]; ++ i ) { t_cnt[t[i]] += 1; }
        
        for ( int i = 0, j = 0; s[i]; ++ i ) {
            if ( t_cnt[s[i]] == 0 ) { continue; }
        
            if ( vis[s[i]] < t_cnt[s[i]] ) { cnt -= 1; }
            vis[s[i]] += 1;
            
            if ( cnt ) { continue; }
            
            while ( vis[s[j]] == 0 || vis[s[j]] > t_cnt[s[j]] ) {
                if ( vis[s[j]] > t_cnt[s[j]] ) { -- vis[s[j]]; }
                ++ j;
            }
            
            if ( i - j + 1 < min_window_length ) {
                min_window_index = j;
                min_window_length = i - j + 1;
            }
        }
        
        return min_window_length == 0x7fffffff ? "" : s.substr(min_window_index, min_window_length);
    }
};
