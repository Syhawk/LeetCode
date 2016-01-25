//uri:	https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/*
 *	采用前序遍历，找出每一层的结点并存储，然后再对某些层的结点逆序。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        v.clear();
        
        preOrder(root, 1);
        
        for(int i = v.size() - 1; i >= 0; -- i) {
            if(i % 2 == 0) continue;
            for(int k = v[i].size() - 1, j = 0; j < k; ++ j, -- k)
                swap(v[i][j], v[i][k]);
        }
        
        return v;
    }
    
    void preOrder(TreeNode* root, int deep) {
        if(root == nullptr) return;
        if(v.size() < deep) {
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
