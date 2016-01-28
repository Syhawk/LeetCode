//uri:	https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
 *	根据中序遍历数列与后序遍历数列直接构造二叉树。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n^2).
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(0, inorder.size() - 1, inorder, postorder.size() - 1, postorder);
    }
    
    TreeNode* createTree(int lhs, int rhs, vector<int>& inorder, int post, vector<int>& postorder) {
        if(lhs > rhs) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[post]);
        
        int p = lhs;
        while(p < rhs && root -> val != inorder[p]) ++ p;
        
        root -> left = createTree(lhs, p - 1, inorder, post - (rhs - p) - 1, postorder);
        root -> right = createTree(p + 1, rhs, inorder, post - 1, postorder);
        
        return root;
    }
};
