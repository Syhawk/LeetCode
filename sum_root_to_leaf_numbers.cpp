//uri:	https://leetcode.com/problems/sum-root-to-leaf-numbers/

/*
 *	采用前序遍历（或者其他二叉树遍历方式）统计一下即可。
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
    int sumNumbers(TreeNode* root) {
        sum = 0;
        preOrder(root, 0);
        
        return sum;
    }
    
    void preOrder(TreeNode* root, int curSum) {
        if(root == nullptr) return;
        if(root -> left == nullptr && root -> right == nullptr) {
            sum += curSum * 10 + root -> val;
            return;
        }
        
        preOrder(root -> left, curSum * 10 + root -> val);
        preOrder(root -> right, curSum * 10 + root -> val);
    }
    
private:
    int sum;
};
