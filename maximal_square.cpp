//uri:	https://leetcode.com/problems/maximal-square/

/*
 *	采用dp，状态转移公式为：dp(i, j) = min(dp(i, j - 1), dp(i - 1, j), dp(i - 1, j - 1)),这是当前
 *	字符为‘1’的时候，如果为‘0’， 那么dp(i, j) = 0.
 *	空间复杂度：O(m * n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) { return 0; }
        int n = matrix[0].size();
        int MAX = 0;
        vector<int> t(n, 0);
        vector<vector<int>> dp(m, t);
        
        for(int i = 0; i < m; ++ i) {
            for(int j = 0; j < n; ++ j) {
                if(matrix[i][j] == '0') { dp[i][j] = 0; }
                else {
                    dp[i][j] = min(min(getDp(dp, i, j - 1), getDp(dp, i - 1, j)), getDp(dp, i - 1, j - 1)) + 1;
                    MAX = max(dp[i][j], MAX);
                }
            }
        }
        
        return MAX * MAX;
    }
    
    int getDp(vector<vector<int>>& dp, int x, int y) {
        if(x < 0 || y < 0) { return 0; }
        return dp[x][y];
    }
};
