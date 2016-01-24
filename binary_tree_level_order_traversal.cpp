//uri:	https://leetcode.com/problems/binary-tree-level-order-traversal/

/*
 *	直接采用前序遍历方式，把对应的深度节点值放到对应的vector中。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        v.clear();
        
        dfs(root, 1);
        
        return v;
    }
    
    void dfs(TreeNode* root, int deep) {
        if(root == nullptr) return;
        if(v.size() < deep) {
            vector<int> t;
            v.push_back(t);
        }
        
        v[deep - 1].push_back(root -> val);
        
        dfs(root -> left, deep + 1);
        dfs(root -> right, deep + 1);
    }
    
private:
    vector<vector<int>> v;
};
