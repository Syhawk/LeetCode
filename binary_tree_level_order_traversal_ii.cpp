//uri:	https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

/*
 *	先前序遍历，把每一层的结点存储起来，然后再把每一层逆序。
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        v.clear();
        
        preOrder(root, 1);
        
        for(int i = 0, j = v.size() - 1; i < j; ++ i, -- j)
            swap(v[i], v[j]);
        
        return v;
    }
    
    void preOrder(TreeNode* root, int deep) {
        if(root == nullptr) return;
        
        if(deep > v.size()) {
            vector<int> t;
            v.push_back(t);
        }
        
        v[deep - 1].push_back(root -> val);
        
        preOrder(root -> left, deep + 1);
        preOrder(root -> right, deep + 1);
    }

private:
    vector<vector<int>> v;
};
