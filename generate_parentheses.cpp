//uri:	https://leetcode.com/problems/generate-parentheses/

/*
 *	卡特兰数全排列。
 *	采用宽度优先遍历（bfs）方式进行选取括号。在一个字符串中，任何一个位置，
 *	左括号数量一定大于等于右括号数量。因此，当左括号大于等于右括号时可以
 *	选择往当前位置添加左括号；当右括号数量已经达到足够要求时或者左括号数量
 *	大于右括号数量，就可以在当前位置添加右括号。
 *	空间复杂度：O(卡特兰数).
 *	时间复杂度：O(卡特兰数).
 * */

struct Node {
    string s;
    int lhs;
    int rhs;
    Node(string x = "", int y = 0, int z = 0) : s(x), lhs(y), rhs(z) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        v.clear();
        if(n < 1) return v;

        queue<Node> q;
        while(!q.empty())
            q.pop();
        q.push({"(", 1, 0});
        while(!q.empty()) {
            Node p = q.front();
            q.pop();
            int lhs = p.lhs;
            int rhs = p.rhs;
            if(lhs == n && rhs == n) {
                v.push_back(p.s);
                continue;
            }
            string s = p.s;
                
            if(lhs == n || lhs > rhs) {
                q.push({s + ')', lhs, rhs + 1});
            }
            if(lhs >= rhs && lhs < n) {
                q.push({s + '(', lhs + 1, rhs});
            }
        }
        
        return v;
    }
};
