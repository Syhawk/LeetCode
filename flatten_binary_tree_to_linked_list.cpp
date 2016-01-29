//uri:	https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*
 *	采用两个变量，当前节点以及上一节点，每次都把两个节点连起来，然后更新节点。
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
    void flatten(TreeNode* root) {
        pre = nullptr;
        cur = nullptr;
        preOrder(root);
        
        if(cur) {
            cur -> left = nullptr;
            cur -> right = nullptr;
        }
    }
    
    void preOrder(TreeNode* root) {
        if(root == nullptr) return;
        
        TreeNode* lhs = root -> left;
        TreeNode* rhs = root -> right;
        
        pre = cur;
        cur = root;
        if(pre) {
            pre -> right = cur;
            pre -> left = nullptr;
        }
        
        preOrder(lhs);
        preOrder(rhs);
    }
    
private:
    TreeNode* pre;
    TreeNode* cur;
};
