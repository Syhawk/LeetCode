//uri:	https://leetcode.com/problems/minimum-path-sum/

/*
 *	寻找从左上角到右下的最小路径和，可以采用动归来解决。状态转移方程为：
 *	dp(i, j) += min(dp(i - 1, j), dp(i, j - 1));
 *	空间复杂度：O(1).
 *	时间复杂度：O(m*n).
 * */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j) {
                if(!i && !j) continue;
                if(j && i) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if(i) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += grid[i][j - 1];
            }
        return grid[m - 1][n - 1];
    }
};
