//uri:	https://leetcode.com/problems/valid-parentheses/

/*
 *	括号匹配可以采用栈来处理，遇到匹配的括号，就从栈中弹出，否则就入栈。
 *	最后判断栈是否为空，为空就说明所有括号匹配成功，否则不成功。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        while(!st.empty())
            st.pop();
        for(int i = 0; s[i]; ++ i) {
            if(st.empty() || !judge(st.top(), s[i])) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        
        return st.empty();
    }
    
    bool judge(char ch1, char ch2) {
        return (ch1 + 1 == ch2 || ch1 + 2 == ch2);
    }
};
