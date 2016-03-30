//uri:	https://leetcode.com/problems/combination-sum-iii/

/*
 *	直接暴力解决即可。数字大小均为1-9且不重复。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> sub;
        
        if(k > 9) return v;
        if((9 + 10 - k) * k / 2 < n) return v;
        dfs(0, n, 0, k, 0, sub, v);
        
        return v;
    }
    
    void dfs(int index, int &n, int seq, int& k, int sum, vector<int>& sub, vector<vector<int>>& v) {
        if(seq == k) {
            v.push_back(sub);
            return;
        }
        
        int i = index + 1;
        if(seq == k - 1 ) { i = n - sum; }
        for( ; i <= 9 && (i + i + k - seq - 1) * (k - seq) / 2 <= n - sum; ++ i) {
            sub.push_back(i);
            dfs(i, n, seq + 1, k, sum + i, sub, v);
            sub.pop_back();
        }
    }
};
