//uri:	https://leetcode.com/problems/edit-distance/

/*
 *	简单dp问题。状态转移方程如下：
 *	dp[i + 1][j + 1] = min(dp[i][j] + (word1[i] == word2[j]), dp[i + 1][j + 1])，
 *	dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]),
 *	dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j])
 *	空间复杂度：O(m * n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_size = word1.size();
        int word2_size = word2.size();
        vector<int> subDp(word2_size + 1, 0xfffffff);
        vector<vector<int>> dp(word1_size + 1, subDp);
        dp[0][0] = 0;
        
        for ( int i = 0; i <= word1_size; ++ i ) {
            for ( int j = 0; j <= word2_size; ++ j ) {
                if ( i < word1_size && j < word2_size ) {
                    if ( word1[i] == word2[j] ) { dp[i + 1][j + 1] = min(dp[i][j], dp[i + 1][j + 1]); }
                    else { dp[i + 1][j + 1] = min(dp[i][j] + 1, dp[i + 1][j + 1]); }
                }
                if ( j < word2_size ) dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
                if ( i < word1_size )  dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};
