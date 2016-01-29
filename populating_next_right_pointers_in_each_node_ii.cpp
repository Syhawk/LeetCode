//uri:	https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
 *	采用宽度优先遍历的方式遍历二叉树，每次保存上一个节点，判断当前节点与
 *	上一个节点的层次关系。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        
        queue<pair<TreeLinkNode*, int>> q;
        q.push(make_pair(root, 0));
        pair<TreeLinkNode*, int> p = make_pair(nullptr, -1);
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if(t.second == p.second) p.first -> next = t.first;
            p = t;
            
            if(p.first -> left) q.push(make_pair(p.first -> left, p.second + 1));
            if(p.first -> right) q.push(make_pair(p.first -> right, p.second + 1));
        }
    }
};
