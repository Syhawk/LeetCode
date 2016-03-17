//uri:	https://leetcode.com/problems/binary-tree-right-side-view/

/*
 *	采用宽度优先遍历，队列中存储树节点指针与深度，每次选取当前深度最后一个位置
 *	的节点值加入数组存储起来。
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == nullptr) { return v; }
        
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> p = make_pair(root, 1);
        q.push(make_pair(root, 1));
        
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            
            if(tmp.first -> left != nullptr) { q.push(make_pair(tmp.first -> left, tmp.second + 1)); }
            if(tmp.first -> right != nullptr) { q.push(make_pair(tmp.first -> right, tmp.second + 1)); }
            
            if(tmp.second != p.second) { v.push_back(p.first -> val); }
            
            p = tmp;
        }
        
        v.push_back(p.first -> val);
        
        return v;
    }
};
