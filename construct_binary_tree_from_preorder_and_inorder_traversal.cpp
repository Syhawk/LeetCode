//uri:	https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
 *	根据前序遍历和中序遍历的输出序列，构造这棵树。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(0, preorder, 0, inorder.size() - 1, inorder);
    }
    
    TreeNode* createTree(int pre, vector<int>& preorder, int lhs, int rhs, vector<int>& inorder) {
        if(lhs > rhs) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre]);
        int i = lhs;
        for( ; i <= rhs && inorder[i] != root -> val; ++ i) ;
        
        root -> left = createTree(pre + 1, preorder, lhs, i - 1, inorder);
        root -> right = createTree(pre + 1 + (i - lhs), preorder, i + 1, rhs, inorder);
        
        return root;
    }
};
