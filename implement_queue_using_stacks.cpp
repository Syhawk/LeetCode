//uri:	https://leetcode.com/problems/implement-queue-using-stacks/

/*
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> _st;
        while (!st.empty()) {
            _st.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        while (!_st.empty()) {
            st.push(_st.top());
            _st.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st.pop();
    }

    // Get the front element.
    int peek(void) {
        return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
    
private:
    stack<int> st;
};
