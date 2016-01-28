//uri:	https://leetcode.com/problems/minimum-depth-of-binary-tree/

/*
 *	每次判断当前结点是否为叶子结点，然后取叶子结点的最小深度。
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
    int minDepth(TreeNode* root) {
        minDeep = 0x7fffffff;
        preOrder(root, 1);
        
        return minDeep == 0x7fffffff ? 0 : minDeep;
    }
    
    void preOrder(TreeNode* root, int deep) {
        if(root == nullptr) {
            return;
        }
        
        if(root -> left == nullptr && root -> right == nullptr) {
            minDeep = min(minDeep, deep);
            return;
        }
        
        if(minDeep <= deep) return;
        
        preOrder(root -> left, deep + 1);
        preOrder(root -> right, deep + 1);
    }
    
private:
    int minDeep;
};
