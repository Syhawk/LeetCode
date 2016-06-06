//uri:	https://leetcode.com/problems/flatten-nested-list-iterator/

/*
 *	采用一个栈来存储vector<NestedInteger>类型的迭代器，迭代器所指对象如果存在值，那么就终止，否则继续查找。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        if ( hasNext() ) {
            auto p = st.top();
            st.pop();
            
            auto q = p;
            st.push(make_pair(++q.first, q.second));
            
            return p.first -> getInteger();
        }
        
        return 0;
    }

    bool hasNext() {
        while ( !st.empty() ) {
            auto p = st.top();
            st.pop();
            if ( p.first == p.second ) { continue; }
            
            if ( p.first -> isInteger() ) {
                st.push(p);
                return true;
            }
            else {
                auto q = p;
                st.push(make_pair(++ q.first, q.second));
                st.push(make_pair(p.first -> getList().begin(), p.first -> getList().end()));
            }
        }
        
        return false;
    }
    
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
