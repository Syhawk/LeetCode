//uri:	https://leetcode.com/problems/path-sum-ii

/*
 *	采用某种遍历二叉树的方式，找出所有路径之和为给定的数值。
 *	空间复杂度：O(n^2).
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        v.clear();
        vector<int> t;
        
        preOrder(root, sum, t);
        
        return v;
    }
    
    void preOrder(TreeNode* root, int sum, vector<int>& t) {
        if(root == nullptr) return;
        t.push_back(root -> val);
        
        if(root -> left == nullptr && root -> right == nullptr && sum == root -> val) {
            v.push_back(t);
        }
        
        preOrder(root -> left, sum - root -> val, t);
        preOrder(root -> right, sum - root -> val, t);
        
        t.pop_back();
    }
    
private:
    vector<vector<int>> v;
};
