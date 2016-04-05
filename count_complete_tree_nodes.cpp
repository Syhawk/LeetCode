//uri:	https://leetcode.com/problems/count-complete-tree-nodes/

/*
 *	采用二分查找的方式，每次判断左右子树的高度差，从而计算当前节点数。
 *	空间复杂度：O(1).
 *	时间复杂度：O(h^2).
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
    int countNodes(TreeNode* root) {
        if(root == nullptr) { return 0; }
        
        int left_h = leftHeight(root);
        int right_h = rightHeight(root);
        if(left_h == right_h) { return (1 << left_h) - 1; }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    int leftHeight(TreeNode* root) {
        int cnt = 0;
        while(root) {
            cnt += 1;
            root = root -> left;
        }
        
        return cnt;
    }
    
    int rightHeight(TreeNode* root) {
        int cnt = 0;
        while(root) {
            cnt += 1;
            root = root -> right;
        }
        
        return cnt;
    }
};
