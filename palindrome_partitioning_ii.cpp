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

/*
 *	相比于上面的方法，时耗更少。
 *	方法二：从当前下标开始到字符串尾后下标查找可能出现的所有回文，并把该回文的下一个下标加入队列。
 *	已经加入队列的下标以后不再加入。最早切割到字符串最后一个字符的切割方式为最优切割方式。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<bool> vis(len, 0);
        queue<pair<int, int>> que;
        
        que.push(make_pair(0, 0));
        
        while( !que.empty() ) {
            auto p = que.front();
            que.pop();
            
            for( int i = len; i > p.first; -- i) {
                int rhs = i - 1;
                int lhs = p.first;
                
                for( ; lhs <= rhs && s[lhs] == s[rhs]; ++ lhs, -- rhs);
                
                if ( lhs <= rhs ) { continue; }
                if( i == len ) { return p.second; }
                
                if ( !vis[i] ) {
                    que.push(make_pair(i, p.second + 1));
                    vis[i] = true;
                }
            }
        }

        return len - 1;
    }
};
