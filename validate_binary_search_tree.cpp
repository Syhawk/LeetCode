//uri:	https://leetcode.com/problems/validate-binary-search-tree/

/*
 *	二分查找树的中序遍历一定是递增有序数列，所以，采用中序遍历的方式进行判别。
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
    bool isValidBST(TreeNode* root) {
        flg = false;
        
        return check(root);
    }
    
    bool check(TreeNode* root) {
        if(root == nullptr) return true;
        
        bool f = check(root -> left);
        if(f == false) return f;
        if(root) {
            if(flg && root -> val <= x) return false;
            
            flg = true;
            x = root -> val;
        }
        
        f = check(root -> right);
        
        return f;
    }
    
private:
    bool flg;
    int x;
};
