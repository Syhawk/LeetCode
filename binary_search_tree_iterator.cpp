//uri:	https://leetcode.com/problems/binary-search-tree-iterator/

/*
 *	采用一个栈，把临时变量全都存储起来，每次访问next()函数就删除一个元素。
 *	空间复杂度：O(h).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(!st.empty()) st.pop();
        while(root) {
            st.push(root);
            root = root -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* root = st.top();
        TreeNode* tmp = root;
        st.pop();
        root = root -> right;
        while(root) {
            st.push(root);
            root = root -> left;
        }
        
        return tmp -> val;
    }
    
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
