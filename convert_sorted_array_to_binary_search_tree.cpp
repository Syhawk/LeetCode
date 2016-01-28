//uri:	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
 *	转换成BST，那么可以根据有序数组二分查找的方式创建相应的节点。
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(0, nums.size() - 1, nums);
    }
    
    TreeNode* createBST(int lhs, int rhs, vector<int>& nums) {
        if(rhs < lhs) return nullptr;
        
        int mid = (rhs + lhs) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = createBST(lhs, mid - 1, nums);
        root -> right = createBST(mid + 1, rhs, nums);
        
        return root;
    }
};
