//uri:	https://leetcode.com/problems/interleaving-string/

/*
 *	dp问题，状态转移方程为：dp(i, j) = (dp(i - 1, j) && s3[i + j] == s1[i]) || (dp(i, j - 1) && s3[i + j] == s2[j])
 *	为了节省空间，可以把二维的dp转化为一维的dp：由于每次dp(i, j)更新只会用到dp(i, j - 1)和dp(i - 1, j)，
 *	那么我们可以用一个一维dp来表示，即dp(j - 1)表示dp(i, j - 1)，dp(j)表示dp(i - 1, j)
 *	空间复杂度：O(n + m).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.size() == 0 ) { return s2 == s3; }
        if ( s2.size() == 0 ) { return s1 == s3; }
        if ( s1.size() + s2.size() != s3.size() ) { return false; }
        
        vector<bool> dp(s2.size() + 1, 0);
        dp[0] = true;
        
        for ( int i = 0; i <= s1.size(); ++ i ) {
            for ( int j = 0; j <= s2.size(); ++ j ) {
                if ( i + j == 0 ) { continue; }
                bool val = false;
                
                if ( j ) { val = (dp[j - 1] && s3[i + j - 1] == s2[j - 1]); }
                if ( i && !val ) { val = (dp[j] && s3[i + j - 1] == s1[i - 1]); }
                
                dp[j] = val;
            }
        }
       
        return dp[s2.size()];
    }
};
