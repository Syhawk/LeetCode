//uri:	https://leetcode.com/problems/same-tree/

/*
 *	两棵树相同的条件是有相当的结构，而且在同一结构位置的节点值必须相同，所以，
 *	直接前序遍历（或者其他遍历方式）判别。
 *	空间复杂度：O(1).
 *	时间复杂度：O(min(n, m)).
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q) || (p && !q)) return false;
        if(!p && !q) return true;
        if(p -> val != q -> val) return false;
        
        bool f = isSameTree(p -> left, q -> left);
        if(f == false) return false;
        f = isSameTree(p -> right, q -> right);
        
        return f;
    }
};
