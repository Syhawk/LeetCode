//uri:	https://leetcode.com/problems/basic-calculator/

/*
 *	采用栈存储变量以及操作运算符，遇到合适的情况就删除栈内相关元素，插入新的元素。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int calculate(string s) {
        stack<pair<int, char>> st;
        
        for ( int i = 0; s[i]; ) {
            while ( s[i] == ' ' ) { ++ i; }
            if ( isdigit(s[i]) ) {
                int val = 0;
                for ( ; isdigit(s[i]); ++ i ) { val = val * 10 + s[i] - '0'; }
                
                while ( !st.empty() && st.top().second != '(' ) {
                    char oper = st.top().second;
                    st.pop();
                    
                    if ( oper == '+' ) { val += st.top().first; }
                    else { val = st.top().first - val; }
                    
                    st.pop();
                }
                st.push(make_pair(val, 0));
            } else if ( s[i] == ')' ) {
                if ( st.top().second ) { st.pop(); }
                else {
                    int val = st.top().first;
                    st.pop();
                    st.pop();
                    
                    while ( !st.empty() && st.top().second != '(' ) {
                        char oper = st.top().second;
                        st.pop();
                        
                        if ( oper == '+' ) { val += st.top().first; }
                        else { val = st.top().first - val; }
                        
                        st.pop();
                    }
                    st.push(make_pair(val, 0));
                }
                
                ++ i;
            } else if ( s[i] ) { st.push(make_pair(0, s[i ++]));  }
        }
        
        return st.empty() ? 0 : st.top().first;
    }
};
