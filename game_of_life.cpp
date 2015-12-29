//uri:	https://leetcode.com/problems/game-of-life/

/*
 *	根据当前状态和变化规则输出下一次Game of Life的下一次状态
 *	空间复杂度：O(1).
 *	时间复杂度：O(m*n).
 * */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	int neighbor[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        int m = board.size();
        int n = board[0].size();

       	for(int i = 0; i < m; ++ i)
       		for(int j = 0; j < n; ++ j) {
        		int positive = 0;

        		for(int k = 0; k < 8; ++ k) {
        			int x = i + neighbor[k][0];
        			int y = j + neighbor[k][1];
        			bool result = check(x, y, m, n);
        			if(result && board[x][y] >= 1) ++ positive;
        		}
        		if(board[i][j]) {
        			if(positive < 2 || positive > 3)
        				board[i][j] = 2;
        		}
        		else {
        			if(positive == 3)
        				board[i][j] = -1;
        		}
        	}

        for(int i = 0; i < m; ++ i)
        	for(int j = 0; j < n; ++ j)
        		if(board[i][j] == 2)
        			board[i][j] = 0;
        		else if(board[i][j] == -1)
        			board[i][j] = 1;
    }

    bool check(int x, int y, int m, int n) {
    	if(x < 0 || y < 0 || x >= m || y >= n)
    		return 0;
    	return 1;
    }
};
