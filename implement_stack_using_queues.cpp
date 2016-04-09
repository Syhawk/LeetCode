//uri:	https://leetcode.com/problems/implement-stack-using-queues/

/*
 *	采用两个队列来实现栈的操作，其中push操作时间复杂度为O(n)，原因是要借助另一个辅助队列实现转换
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> t;
        while(!q.empty()) {
            t.push(q.front());
            q.pop();
        }
        
        q.push(x);
        
        while(!t.empty()) {
            q.push(t.front());
            t.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};
