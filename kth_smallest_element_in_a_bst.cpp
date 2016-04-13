//uri:	https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
 *	前序遍历查找元素。
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while (root) {
            st.push(root);
            root = root -> left;
        }
        
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            if (k == 1) { return p -> val; }
            
            k -= 1;
            if (p -> right == nullptr) { continue; }
            p = p -> right;
            while (p) {
                st.push(p);
                p = p -> left;
            }
        }
        
        return 0;
    }
};
