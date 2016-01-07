//uri:	https://leetcode.com/problems/combinations/

/*
 *	直接遍历所有可能情况即可。
 *	空间复杂度：O(C(n, k)).
 *	时间复杂度：O(C(n, k)).
 *	表示从n个数里面选k个数
 * */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        v.clear();
        vector<int> t;
        dfs(1, n, k, t);
        return v;
    }
    
    void dfs(int index, int len, int k, vector<int>& t) {
        if(k <= 0) {
            v.push_back(t);
            return;
        }
        
        for(int i = index; i <= len - k + 1; ++ i) {
            t.push_back(i);
            if(len - i >= k - 1) dfs(i + 1, len, k - 1, t);
            t.pop_back();
        }
    }
    
private:
    vector<vector<int>> v;
};
