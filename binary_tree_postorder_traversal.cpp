//uri:	https://leetcode.com/problems/binary-tree-postorder-traversal/

/*
 *	后序遍历方式是先访问左子树，再访问右子树，最后访问父节点。
 *	可以采用一个stack来存储中间变量，栈内元素为树节点指针与一个bool值值对，bool值为true，表示该节点右子树未访问，
 *	否则表示已经访问过。
 *	空间复杂度：O(h).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> st;
        vector<int> traversal;
        
        while ( root ) {
            st.push(make_pair(root, true));
            root = root -> left;
        }
        
        while ( !st.empty() ) {
            auto p = st.top();
            st.pop();
            if ( p.second == false ) {
                traversal.push_back(p.first -> val);
                continue;
            }
            
            st.push(make_pair(p.first, false));
            auto root = p.first -> right;
            while ( root ) {
                st.push(make_pair(root, true));
                root = root -> left;
            }
        }
        
        return traversal;
    }
};
