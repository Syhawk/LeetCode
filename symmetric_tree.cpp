//uri:	https://leetcode.com/problems/symmetric-tree/

/*
 *	判别一棵树是不是对称树，可以采用前序遍历（或者其他遍历方式）直接判断左右子树。
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return dfs(root -> left, root -> right);
    }
    
    bool dfs(TreeNode* lhs, TreeNode* rhs) {
        if(!lhs && !rhs) return true;
        if(!lhs && rhs) return false;
        if(lhs && !rhs) return false;
        if(lhs && rhs && lhs -> val != rhs -> val) return false;

        bool flg = true;
        flg = dfs(lhs -> left, rhs -> right);
        if(!flg) return false;

        flg = dfs(lhs -> right, rhs -> left);
        if(!flg) return false;

        return true;
    }
};
