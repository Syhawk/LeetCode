//uri:	https://leetcode.com/problems/min-stack/

/*
 *	借用一个栈存储当前变量以及到当前为止最小的元素值。
 *	空间复杂度：O(n).
 *	时间复杂度：O(1).
 * */

class MinStack {
public:
    void push(int x) {
        if(st.empty()) st.push(make_pair(x, x));
        else st.push(make_pair(x, min(getMin(), x)));
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    stack<pair<int, int>> st;
};
