//uri:	https://leetcode.com/problems/n-queens/

/*
 *	方法有两种，第一种：每添加一个皇后，那么就记录横向、竖向以及斜向四个方向重叠情况，分别用四个一维数组来记录。但是耗时比较多。
 *	第二种：群论，即每次选取可能解集里的二维数组下标来填放皇后。耗时较少。
 *	空间复杂度：O(n! * n ^ 2).
 *	时间复杂度：O(n! * n ^ 2).
 * */

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        struct Solver {
            vector<bool> col;
            vector<bool> plus;
            vector<bool> sub;
            vector<int> board;
            
            Solver(int n) : col(vector<bool> (n)), plus(vector<bool> (n * 2)), sub(vector<bool> (n * 2)) { }
        };
        
        vector<vector<string>> result;
        queue<Solver> q;
        q.push(Solver(n));
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.board.size();
            
            if (x == n) {
                countBoards(result, p.board);
                continue;
            }
            
            for (int y = 0; y < n; ++ y) {
                if (p.col[y] || p.plus[x + y] || p.sub[x - y + n]) { continue; }
                
                p.col[y] = true;
                p.plus[x + y] = true;
                p.sub[x - y + n] = true;
                p.board.push_back(y);
                
                q.push(p);
                
                p.col[y] = false;
                p.plus[x + y] = false;
                p.sub[x - y + n] = false;
                p.board.pop_back();
            }
        }
        
        return result;
    }
    
    void countBoards(vector<vector<string>>& result, vector<int>& board) {
        int len = board.size();
        vector<string> _r;
        for (int i = 0; i < len; ++ i) {
            string s = "";
            for (int j = 0; j != board[i]; ++ j) { s += '.'; }
            s += 'Q';
            for (int j = board[i] + 1; j < len; ++ j) { s += '.'; }
            
            _r.push_back(s);
        }
        
        result.push_back(_r);
    }
};


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> _r;
        result.clear();
        len = n;
        
        dfs((1 << n) - 1, 0, 0, _r);
        
        return result;
    }
    
    void dfs(int solver, int lhs, int rhs, vector<string>& _r) {
        if (len == _r.size()) {
            result.push_back(_r);
            return;
        }
        
        int _solver = solver & ~(lhs | rhs);
        string s(len, '.');
        while (_solver) {
            int p = _solver & (~_solver + 1);
            _solver -= p;
            
            int i = 0;
            for (int t = p >> 1; t && ++ i; t >>= 1) ;
            s[i] = 'Q';
            _r.push_back(s);
            s[i] = '.';
            
            dfs(solver - p, (lhs | p) >> 1, (rhs | p) << 1, _r);
            
            _r.pop_back();
        }
    }
    
private:
    vector<vector<string>> result;
    int len;
};
