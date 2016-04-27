//uri:	https://leetcode.com/problems/scramble-string/

/*
 *	dp问题。状态转移方程： dp[i][j][len] =
 *	                      (dp[i][j][k] && dp[i + k + 1][j + k + 1][len - k - 1]) | (dp[i][j + len - k][k] && dp[i + k + 1][j][len - k - 1]);
 *	i表示字符串s1的下标，j表示字符串s2的下标，len表示字符串从当前下标开始的len + 1个字符.
 *	dp[i][j][len]表示s1从下标i处开始的len + 1个字符与s2从下标j处开始的len + 1个字符比较的结果。
 *	len + 1长度的字符串可以分为两段[0, k], [k + 1, len]这两段，字符串s1与s2有不同的选择：
 *	s1的[0, k]与s2的[0, k]比较，s1与s2的[k + 1, len]比较；
 *	或者s1的[0, k]与s2的[len - k, len]比较，s1的[k + 1, len]与s2的[0, len - k - 1]比较。
 *
 *	空间复杂度：O(n ^ 3).
 *	时间复杂度：O(n ^ 4).
 * */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size = s1.size();
        bool dp[size][size][size];
                
        for ( int len = 0; len < size; ++ len ) {
            for ( int i = 0; i < size - len; ++ i ) {
                for ( int j = 0; j < size - len; ++ j ) {
                    if ( len == 0 ) {
                        dp[i][j][len] = (s1[i] == s2[j]);
                        continue;
                    }
                    
                    dp[i][j][len] = false;
                    for ( int k = 0; k < len && !dp[i][j][len]; ++ k ) {
                        dp[i][j][len] = 
                        (dp[i][j][k] && dp[i + k + 1][j + k + 1][len - k - 1]) | (dp[i][j + len - k][k] && dp[i + k + 1][j][len - k - 1]);
                    }
                }
            }
        }
        
        return dp[0][0][size - 1];
    }
};

