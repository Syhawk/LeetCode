//uri:	https://leetcode.com/problems/invert-binary-tree/

/*
 *	每次递归时，交换数的左右子树指针。
 *	空间复杂度：O(1).
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        root -> right = invertTree(left);
        root -> left = invertTree(right);
        
        return root;
    }
};
