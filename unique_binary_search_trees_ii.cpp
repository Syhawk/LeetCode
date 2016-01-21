//uri:	https://leetcode.com/problems/unique-binary-search-trees-ii/

/*
 *	采用动归方式求解所有可能值。先求出当前结点子树的所有可能状态，然后进行组合。
 *	空间复杂度：O(卡特兰数).
 *	时间复杂度：O(卡特兰数).
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n < 1) return v;
        return createTree(1, n);
    }
    
    vector<TreeNode*> createTree(int l, int r) {
        vector<TreeNode*> v;
        if(l > r) v.push_back(nullptr);
        
        for(int i = l; i <= r; ++ i) {
            vector<TreeNode*> left = createTree(l, i - 1);
            vector<TreeNode*> right = createTree(i + 1, r);
            
            for(int j = left.size() - 1; j >= 0; -- j) {
                for(int k = right.size() - 1; k >= 0; -- k) {
                    
                    TreeNode* root = new TreeNode(i);
                    root -> left = left[j];
                    root -> right = right[k];
                    
                    v.push_back(root);
                }
            }
        }
        
        return v;
    }
};
