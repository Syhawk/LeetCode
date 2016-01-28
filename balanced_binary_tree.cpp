//uri:	https://leetcode.com/problems/balanced-binary-tree/

/*
 *	直接判断平衡二叉树的左右子树高度差。
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
    bool isBalanced(TreeNode* root) {
        flg = true;
        check(root, 0);
        
        return flg;
    }
    
    int check(TreeNode* root, int deep) {
        if(root == nullptr) return deep;
        int lhs = check(root -> left, deep + 1);
        
        if(flg == false) return -1;
        
        int rhs = check(root -> right, deep + 1);
        
        if(abs(lhs - rhs) > 1) flg = false;
        
        return max(lhs, rhs);
    }
    
private:
    bool flg;
};
