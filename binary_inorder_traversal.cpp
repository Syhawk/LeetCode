//uri:	https://leetcode.com/problems/binary-tree-inorder-traversal/

/*
 *	中序遍历输出节点值
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        inorderTravel(root, v);
        
        return v;
    }
    
    void inorderTravel(TreeNode* root, vector<int>& v) {
        if(!root) return;
        
        inorderTravel(root -> left, v);
        v.push_back(root -> val);
        inorderTravel(root -> right, v);
    }
};
