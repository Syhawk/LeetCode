//uri:	https://leetcode.com/problems/palindrome-partitioning-ii/

/*
 *	dp问题：状态转移方程为：dp[i][len - 1] = min(dp[i][len - 1], dp[i][j] + dp[j + 1][len - 1] + 1)
 *	dp[i][j]表示字符串从下标i到下标j之间的最小切割次数；如果是回文，那么切割次数为0。
 *	基于以上状态方程，我们可以优化空间复杂度，将二维dp优化为一维dp，那么dp[i]表示dp[i][len - 1]
 *	状态方程变为：dp[i] = min(dp[i], dp[i][j] + dp[j + 1] + 1)
 *	其中dp[i][j]我们可以优化为一个bool类型的数组，表示字符串s从下标i到j是否为回文，即palin[j] = dp[i][j].
 *	s[i]～s[j]为回文，必然由上一层s[i + 1]～s[j - 1]得到，所以，可以优化为一维。
 *	空间复杂度：O(n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int dp[len + 1];
        vector<bool> palin(len, 0);
        for ( int i = 0; i <= len; ++ i ) { dp[i] = len - i - 1; }
        
        for ( int i = len - 2; i >= 0; -- i ) {
            bool flg = true;
            for ( int j = i; j < len; ++ j ) {
                bool _flg = false;
                if ( s[i] == s[j] && ( flg || j - i < 2 ) ) {
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                    _flg = true;
                }
                flg = palin[j];
                palin[j] = _flg;
            }
        }
        
        return dp[0];
    }
};
