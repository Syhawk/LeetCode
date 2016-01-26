//uri:	https://leetcode.com/problems/maximum-depth-of-binary-tree/

/*
 *	求一棵树得最大深度，直接递归即可。
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
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int deep) {
        if(root == nullptr) return deep;
        
        return max(dfs(root -> left, deep + 1), dfs(root -> right, deep + 1));
    }
};
