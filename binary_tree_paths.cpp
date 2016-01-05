//uri:	https://leetcode.com/problems/binary-tree-paths/

/*
 *	根据样例可得，遍历方式是前序遍历，所以直接用前序遍历把路径信息存储并返回。
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
    vector<string> binaryTreePaths(TreeNode* root) {
        paths.clear();
        flg = false;
        string path = "";
        
        if(root) dfs(root, path);
        
        return paths;
    }
    
    void dfs(TreeNode* root, string path) {
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        
        if(flg) path += "->";
        path += to_string(root -> val);
        flg = true;
        
        if(left) dfs(left, path);
        if(right) dfs(right, path);
        
        if(!left && !right) paths.push_back(path);
    }
    
private:
    bool flg;
    vector<string> paths;
};
