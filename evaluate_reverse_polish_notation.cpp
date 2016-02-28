//uri:	https://leetcode.com/problems/evaluate-reverse-polish-notation/

/*
 *	后缀表达式，采用栈来保存变量实现。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> st;
        for(int i = 0; i < len; ++ i) {
            bool flg = false;
            for(int j = 0; tokens[i][j]; ++ j) {
                if(!isdigit(tokens[i][j])) continue;
                st.push(stoi(tokens[i]));
                flg = true;
                break;
            }
            
            if(flg == true) continue;
            int x = st.top();
            st.pop();
            switch(tokens[i][0]) {
                case '+' :
                    x += st.top();
                    break;
                case '-' :
                    x = st.top() - x;
                    break;
                case '/' :
                    x = st.top() / x;
                    break;
                case '*' :
                    x *= st.top();
                    break;
                default:
                    break;
            }
            
            st.pop();
            st.push(x);
        }
        
        return st.top();
    }
};
