//uri:	https://leetcode.com/problems/distinct-subsequences/

/*
 *	dp问题。状态转移方程：
 *	s[i] == t[j] => dp(i, j) = dp(i - 1, j - 1) + dp(i - 1, j)
 *	s[i] != t[j] => dp(i, j) = dp(i - 1, j)
 *	意思是如果s[i] == t[j]，当前的字符可以保留，也可以抛弃；保留就是上一状态dp(i - 1, j - 1)，抛弃就是状态dp(i - 1, j),
 *	两者之和构成了当前状态。
 *	如果s[i] != t[j]，那么只能抛弃上一状态dp(i - 1, j - 1)，仅剩下状态dp(i - 1, j)
 *	为了减少空间复杂度，可以把二维空间降为一维空间。
 *	空间复杂度：O(n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    int numDistinct(string s, string t) {
        if ( s.size() < t.size() ) { return 0; }
        
        vector<int> dp(t.size() + 1, 0);
        dp[0] = 1;
        for ( int i = 1; s[i - 1]; ++ i ) {
            int i_1_j = dp[0];
            for ( int j = 1; t[j - 1]; ++ j ) {
                int i_j = dp[j];
                if ( s[i - 1] == t[j - 1] ) { dp[j] += i_1_j; }
                i_1_j = i_j;
            }
        }
        
        return dp[t.size()];
    }
};
