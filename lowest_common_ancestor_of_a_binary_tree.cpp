//uri:	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/*
 *	在二叉树中查找两个节点的最近公共祖先，可以采用一个标志位flg，flg = 0
 *	表示一个节点也没在二叉树中找到；flg = 1表示找到了其中的一个节点；flg = 2
 *	表示两个节点都找到了，这时候就要查找最近公共祖先了：一、公共祖先是两个节点
 *	中的一个；二、公共祖先是其他节点中的一个。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        if(p == q) return p;

        ancestor = NULL;
        dfs(root, p, q);

        return ancestor;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        int tmp = flg;
        if(root == p) ++ flg;
        if(root == q) ++ flg;
        if(flg == 2) return;

        TreeNode* left = root -> left;
        TreeNode* right = root -> right;

        if(left && flg < 2) dfs(left, p, q);
        if(right && flg < 2) dfs(right, p, q);
        if(tmp == 0 && flg == 2) ancestor = root, flg = 3;
    }
    
private:
    int flg;
    TreeNode* ancestor;
};
