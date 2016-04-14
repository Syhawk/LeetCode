//uri:	https://leetcode.com/problems/wildcard-matching/

/*
 *	直接暴力+剪枝，用二维数组记录字符串s和p的下标是否已经访问过，如果访问过，就不再访问。
 *	这种方法耗时很多，改写成非递归形式能够大幅度降低时耗（如下面的非递归形式）。
 *	空间复杂度：O(m * n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> t(p.size() + 1, 0);
        vector<vector<bool>> vis(s.size() + 1, t);
        
        return dfs(s, 0, p, 0, vis);
    }
    
    bool dfs(string& s, int lhs, string& p, int rhs, vector<vector<bool>>& vis) {
        if (p[rhs] == '\0') { return s[lhs] == '\0'; }
        if (s[lhs] == '\0') {
            for(; p[rhs] && p[rhs] == '*'; ++ rhs);
            return p[rhs] == '\0';
        }
        if (vis[lhs][rhs]) { return false; }
        vis[lhs][rhs] = true;
        
        if (s[lhs] == p[rhs] || p[rhs] == '?') { return dfs(s, lhs + 1, p, rhs + 1, vis); }
        if (p[rhs] != '*') { return false; }
        bool flg = dfs(s, lhs, p, rhs + 1, vis);
        for ( ; flg == false && s[lhs]; ++ lhs) { flg = dfs(s, lhs + 1, p, rhs + 1, vis); }
        
        return flg;
    }
};


/*
 *	空间复杂度：O(1).
 *	时间复杂度：O(m * n).
 *	非递归形式，此种方式，每遇到'*'字符，就遍历所有的可能性，直到遇到下一个字符'*'
 * */

class Solution {
public:
    bool isMatch(string& s, string& p) {
        int i = 0;
        for ( ; s[i] && p[i] && (s[i] == p[i] || p[i] == '?'); ++ i);
        
        int j = i;
        while (p[j] == '*' && s[i]) {
            int _i = i;
            int _j = ++ j;
            while (s[i] && p[j] != '*') {
                if (s[i] == p[j] || p[j] == '?') {
                    ++ i;
                    ++ j;
                } else {
                    i = ++ _i;
                    j = _j;
                }
            }
        }
        
        while (p[j] == '*') ++ j;
        
        if (s[i] != '\0') { return false; }
        return p[j] == '\0';
    }
};
