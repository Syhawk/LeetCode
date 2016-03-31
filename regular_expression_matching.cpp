//uri:	https://leetcode.com/problems/regular-expression-matching/

/*
 *	数据量不大，所以可以采用vis数组进行标记是否访问过，这样可以大幅度降低时耗。
 *	空间复杂度：O(m * n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> v(p.size() + 1, 0);
        vector<vector<bool> > vis(s.size() + 1, v);

        return dfs(s, 0, p, 0, vis);
    }
    
    bool dfs(string& s, int s_len, string& p, int p_len, vector<vector<bool> >& vis) {
        if(vis[s_len][p_len]) { return false; }
        vis[s_len][p_len] = true;
        
        if(p[p_len] == '\0') { return s[s_len] == '\0'; }
        
        if(p[p_len + 1] == '*') {
            if(dfs(s, s_len, p, p_len + 2, vis)) { return true; }
            for( ; s[s_len]; ++ s_len) {
                if((p[p_len] == s[s_len] || p[p_len] == '.')) {
                    vis[s_len][p_len] = true;
                    if(dfs(s, s_len + 1, p, p_len + 2, vis)) { return true; }
                }
                else { break; }
            }
            
            return false;
        }
        
        return s[s_len] && (s[s_len] == p[p_len] || p[p_len] == '.') ? dfs(s, s_len + 1, p, p_len + 1, vis) : false;
    }
};
