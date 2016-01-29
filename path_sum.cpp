//uri:	https://leetcode.com/problems/path-sum/

/*
 *	直接按照前序（或其他遍历方式）进行判别，但是要判断到叶子节点。
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root -> left == nullptr && root -> right == nullptr) {
            if(sum == root -> val) return true;
            return false;
        }
        
        return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
    }
};
