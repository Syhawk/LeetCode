//uri:	https://leetcode.com/problems/longest-valid-parentheses/

/*
 *	方法有两种，一种是采用dp：从大往小方向遍历：如果s[i] == '(' && s[j] == ')'且区间(i, j)括号是匹配的，
 *	那么，dp(i) = dp(i + 1) + 2. 否则，dp(i) = 0;如果在满足条件匹配成功的情况下依然满足j + 1 < len，
 *	那么，dp(i) += dp(j + 1).
 *	另一个种方法用栈：从小往大方向遍历，st中存储未匹配的字符和字符'#'，并用一个int数捆绑在一块表示当前
 *	处已经匹配了多少对括号。首先判断是否满足匹配条件；然后判断是否存在'#'，如果存在，那么先把'#'取出来，
 *	并把'#'所捆绑的数字累加合并，再次判断是否匹配，然后再次合并'#'，然后把合并之后'#'放入栈中。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> dp(len, 0);
        int length = 0;
        
        for(int i = len - 2; i >= 0; -- i) {
            if(s[i] == ')') { continue; }
            
            int j = i + 1 + dp[i + 1];
            if(j >= len || s[j] != ')') { continue; }
            
            dp[i] = dp[i + 1] + 2;
            
            if(j + 1 < len) { dp[i] += dp[j + 1]; }
            
            length = max(length, dp[i]);
        }
        
        return length;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        int length = 0;
        int cnt = 0;
        for(int i = 0; s[i]; ++ i) {
            if(s[i] == '(' || st.empty() || st.top().first == ')') {
                st.push(make_pair(s[i], 0));
                continue;
            }
            
            int cnt = 0;
            while(!st.empty() && st.top().first == '#') {
                cnt += st.top().second;
                st.pop();
            }
            
            bool flg = false;
            if(!st.empty() && st.top().first == '(') {
                cnt += 1;
                st.pop();
                flg = true;
            }
            
            while(!st.empty() && st.top().first == '#') {
                cnt += st.top().second;
                st.pop();
            }
            
            st.push(make_pair('#', cnt));
            if(!flg) { st.push(make_pair(s[i], 0)); }
            
            length = max(length, cnt);
        }
        
        return length * 2;
    }
};
