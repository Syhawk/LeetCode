//uri:	https://leetcode.com/problems/binary-tree-preorder-traversal/

/*
 *	前序遍历。
 *	空间复杂度：O(n).
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preOrder(root, v);
        
        return v;
    }
    
    void preOrder(TreeNode* root, vector<int>& v) {
        if(root == nullptr) return;
        v.push_back(root -> val);
        
        preOrder(root -> left, v);
        preOrder(root -> right, v);
    }
};
