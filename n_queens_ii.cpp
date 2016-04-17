//uri:	https://leetcode.com/problems/n-queens-ii/

/*
 *	根据群论，每次只选取可能的解集，而不去遍历那些已经被去除的解集。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n!).
 * */

class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        dfs((1 << n) - 1, 0, 0, n, cnt);
        
        return cnt;
    }
    
    void dfs(int solver, int lhs, int rhs, int n, int& cnt) {
        if (n == 0) {
           cnt += 1;
           return;
        }
        
        int _solver = solver & ~(lhs | rhs);
        while (_solver) {
            int p = _solver & (~_solver + 1);
            _solver ^= p;
            
            dfs(solver ^ p, (lhs | p) << 1, (rhs | p) >> 1, n - 1, cnt);
        }
    }
};
