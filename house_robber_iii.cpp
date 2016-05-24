//uri:	https://leetcode.com/problems/house-robber-iii/

/*
 *	树形dp，返回值有两个，一个是加入当前元素值的结果，另一个是不加入当前元素值的结果。
 *	加入当前元素值：dp(root, 0) = dp(left, 1) + dp(right, 1) + root -> val;
 *	不加入当前元素值：
 *	dp(root, 1) = max(dp(left, 0) + dp(right, 0), dp(left, 1) + dp(right, 0), dp(left, 0) + dp(right, 1), dp(left, 1) + dp(right, 1))
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
    int rob(TreeNode* root) {
        auto money = dfs(root);
        return max(money.first, money.second);
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if ( root == nullptr ) { return make_pair(0, 0); }
        
        auto left = dfs(root -> left);
        auto right = dfs(root -> right);
        
        auto result = make_pair(left.second + right.second + root -> val, left.first + right.first);
        result.second = max(result.second, left.first + right.second);
        result.second = max(result.second, left.second + right.first);
        result.second = max(result.second, left.second + right.second);
        
        return result;
    }
};
