//uri:	https://leetcode.com/problems/maximal-rectangle/

/*
 *	借用一个数组用来表示从当前行到顶端连续的字符'1'的个数。
 *	该题目实际上就是多次最大历史矩形和，所以，我们只需要计算好这个数组所能表示的最大矩形面积即可。
 *	最大矩形面积计算我们借用一个栈来实现，这个栈用来保存数组递增序列的下标。
 *	那么，就可以通过计算栈内的栈顶元素与下一个栈顶元素的区间和来判定是否为最大区间和。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if ( row < 1 ) { return 0; }
        int col = matrix[0].size();
        int MAX = 0;
        vector<int> dp(col + 1, 0);
        
        for ( int i = 0; i < row; ++ i ) {
            for ( int j = 0; j < col; ++ j ) {
                if ( matrix[i][j] == '0' ) { dp[j] = 0; }
                else { dp[j] += 1; }
            }

            stack<int> st;
            for ( int j = 0; j <= col; ) {
                if ( st.empty() || dp[st.top()] < dp[j] ) {
                    st.push(j);
                    ++ j;
                    continue;
                }
                
                int pre = dp[st.top()];
                st.pop();
                MAX = max(MAX, pre * (st.empty() ? j : j - st.top() - 1));
            }
        }
        
        return MAX;
    }
};
