//uri:	https://leetcode.com/problems/triangle/

/*
 *	简单动态规划：dp(i, j) += min(dp(i + 1, j), dp(i + 1, j + 1))
 *	空间复杂度：O(1).
 *	时间复杂度：O(n^2).
 * */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; -- i) {
            for(int j = i; j >= 0; -- j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
        
        return triangle[0][0];
    }
};
