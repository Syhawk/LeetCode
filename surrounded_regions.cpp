//uri:	https://leetcode.com/problems/surrounded-regions/

/*
 *	按照规则进行字符变换即可。
 *	空间复杂度：O(m*n).
 *	时间复杂度：O(m*n).
 * */

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if(m < 1) return;
        int n = board[0].size();
        
        vector<vector<bool>> vis;  
        vector<bool> t(n, false);
        
        for(int i = 0; i < m; ++ i)
        	vis.push_back(t);
        	
        for(int i = 1; i < m - 1; ++ i)
        	for(int j = 1; j < n - 1; ++ j) {
        		if(vis[i][j] || board[i][j] == 'X') continue;
        		if(bfs(i, j, board, m, n, vis)) modify(i, j, board);
        	}
    }

    bool bfs(int x, int y, vector<vector<char>>& board, int m, int n, vector<vector<bool>>& vis) {
        vis[x][y] = true;
    	queue<pair<int, int>> q;
    	q.push(make_pair(x, y));
    	bool flg = true;
    	
    	while(!q.empty()) {
    		auto p = q.front();
    		q.pop();
    		
    		for(int i = 0; i < 4; ++ i) {
    		    x = p.first + dir[i][0];
    		    y = p.second + dir[i][1];
    		    if(x < 0 || y < 0 || x >= m || y >= n) {
    			    flg = false;
    			    continue;
    		    }
    		    
    		    if(vis[x][y] || board[x][y] == 'X') continue;
    		    vis[x][y] = true;
    		    
    			q.push(make_pair(x, y));
    		}
    	}
    	
    	return flg;
    }

    void modify(int x, int y, vector<vector<char>> &board) {
    	queue<pair<int, int>> q;
    	q.push(make_pair(x, y));
    	board[x][y] = 'X';
    	
    	while(!q.empty()) {
    		auto p = q.front();
    		q.pop();
    		
    		for(int i = 0; i < 4; ++ i) {
    		    x = p.first + dir[i][0];
    		    y = p.second + dir[i][1];
    		    
    		    if(board[x][y] == 'X') continue;
    		    board[x][y] = 'X';
    		    
    			q.push(make_pair(x, y));
    		}
    	}
    }
};
