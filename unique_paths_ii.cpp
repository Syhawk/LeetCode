//uri:	https://leetcode.com/problems/unique-paths-ii/

/*
 *	计算从矩阵左上角到右下角的所有唯一路径数目，其中矩阵存在障碍物，障碍物用数字1
 *	来表示，那么可以用负数来表示路径可达，最后再把负数求正即可。
 *	空间复杂度：O(1).
 *	时间复杂度：O(m*n).
 * */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> &p = obstacleGrid;
        if(p[0][0] == 1) return 0;
        int m = p.size();
        int n = p[0].size();
        if(p[0][0] == 1 || p[m - 1][n - 1] == 1) return 0;

        p[0][0] = -1;
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j) {
                if(p[i][j] == 1) continue;
                
                if(i - 1 >= 0 && p[i - 1][j] != 1)
                    p[i][j] += p[i - 1][j];
                if(j - 1 >= 0 && p[i][j - 1] != 1)
                    p[i][j] += p[i][j - 1];
            }
        return -p[m - 1][n - 1];
    }
};
