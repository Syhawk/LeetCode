//uri:	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
 *	在二分查找树查找两个节点的最近公共祖先可以利用其前序遍历是非递减数组的特性，
 *	进行二分查找。
 *	空间复杂度：O(1).
 *	时间复杂度：O(logn).
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        
        int val = root -> val;
        int mini = min(p -> val, q -> val);
        int maxi = max(p -> val, q -> val);
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        
        if(val >= mini && val <= maxi) return root;
        else if(val > maxi) return lowestCommonAncestor(left, p, q);
        else return lowestCommonAncestor(right, p, q);
    }
};
