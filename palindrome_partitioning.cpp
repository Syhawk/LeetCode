//uri:	https://leetcode.com/problems/palindrome-partitioning/

/*
 *	枚举字符串的所有子集并判断。
 *	空间复杂度：O(2^n).
 *	时间复杂度：O(2^n).
 * */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        v.clear();
        vector<string> strs;
        if(s.size() < 1) return v;
        
        dfs(s, 0, strs);
        
        return v;
    }
    
    void dfs(string& s,  int index, vector<string>& strs) {
        if(s[index] == '\0') {
            v.push_back(strs);
            return;
        }
        
        for(int i = index; s[i]; ++ i) {
            if(!check(index, i, s)) continue;
            
            strs.push_back(s.substr(index, i - index + 1));
            dfs(s, i + 1, strs);
            strs.pop_back();
        }
    }
    
    bool check(int lhs, int rhs, string& s) {
        while(lhs <= rhs && s[lhs] == s[rhs]) {
            ++ lhs;
            -- rhs;
        }
        
        return lhs > rhs ? true : false;
    }
    
private:
    vector<vector<string>> v;
};
