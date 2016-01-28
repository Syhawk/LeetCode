//uri:	https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
 *	链表不支持随机访问，所以，将链表的每个节点的指针存储下来，然后采用
 *	二分查找的方式构建平衡二叉树。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> v;
        while(head) {
            v.push_back(head);
            head = head -> next;
        }
        
        return createBST(0, v.size() - 1, v);
    }
    
    TreeNode* createBST(int lhs, int rhs, vector<ListNode*>& v) {
        if(rhs < lhs) return nullptr;
        int mid = (rhs + lhs) >> 1;
        
        TreeNode* root = new TreeNode(v[mid] -> val);
        root -> left = createBST(lhs, mid - 1, v);
        root -> right = createBST(mid + 1, rhs, v);
        
        return root;
    }
};
