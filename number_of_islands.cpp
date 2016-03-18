//uri:	https://leetcode.com/problems/number-of-islands/

/*
 *	每次判断存在字符'1'是否存在，如果存在，那就采用深度优先遍历，将所有与此字符
 *	相连满足条件的'1'变为0，Island数目增加1。
 *	空间复杂度：O(1).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row <= 0) return 0;
        int col = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < row; ++ i) {
            for(int j = 0; j < col; ++ j) {
                if(grid[i][j] != '1') continue;
                
                dfs(i, j, row, col, grid);
                cnt +=1;
            }
        }
        
        return cnt;
    }
    
    void dfs(int x, int y, const int& row, const int& col, vector<vector<char>>& grid) {
        if(x < 0 || x >= row || y < 0 || y >= col) return;
        if(grid[x][y] != '1') return;
        grid[x][y] = '0';
        
        for(int i = 0; i < 4; ++ i) {
            dfs(x + dir[i][0], y + dir[i][1], row, col, grid);
        }
    }

private:
    const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
