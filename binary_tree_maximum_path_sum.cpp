//uri:	https://leetcode.com/problems/binary-tree-maximum-path-sum/

/*
 *	该题目是从一颗二叉树中寻找一条路经，使得这条路径的路径和最大。
 *	当前节点的最大路径和可以表示为：left_path_sum + right_path_sum + father_path_sum - min(前面三个路径和最小的一个) + val(当前节点值)
 *	其中，路径和如果 < 0，就取为0，否则为本身。
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
    int maxPathSum(TreeNode* root) {
        max_path_sum = 0x80000000;
        dfs(root, 0);
        
        return max_path_sum;
    }
    
    int dfs(TreeNode* root, int sum) {
        if ( root == nullptr ) { return 0; }
        
        if ( sum < 0 ) { sum = 0; }
        int left = dfs(root -> left, sum + root -> val);
        int right = dfs(root -> right, sum + root -> val);
        
        if ( left < 0 ) { left = 0; }
        if ( right < 0 ) { right = 0; }
        int cnt_sum = sum + left + right - min(min(left, right), sum);
        max_path_sum = max(max_path_sum, cnt_sum + root -> val);
        
        return max(left, right) + root -> val;
    }

private:
    int max_path_sum;
};
