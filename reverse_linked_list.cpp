//uri:	https://leetcode.com/problems/reverse-linked-list/

/*
 *	将一个链表直接就地逆转。
 *	空间复杂度：O(1).
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while(head) {
            ListNode* post = head -> next;
            head -> next = pre;
            pre = head;
            head = post;
        }
        
        return pre;
    }
};
