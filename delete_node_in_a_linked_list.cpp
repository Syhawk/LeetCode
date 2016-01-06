//uri:	https://leetcode.com/problems/delete-node-in-a-linked-list/

/*
 *	删除所给出的节点。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        *node = *node -> next;
    }
};
