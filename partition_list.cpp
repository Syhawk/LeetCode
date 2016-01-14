//uri:	https://leetcode.com/problems/partition-list/

/*
 *	将链表分为两部分，一部分的值小于x，另一部分则相反，然后拼接起来，第一部分在前
 *	，第二部分在后。
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = nullptr, *p1;
        ListNode* l2 = nullptr, *p2;
        while(head) {
            if(head -> val < x) {
                if(l1 == nullptr) {
                    l1 = head;
                    p1 = head;
                } else {
                    p1 -> next = head;
                    p1 = head;
                }
            } else {
                if(l2 == nullptr) {
                    l2 = head;
                    p2 = head;
                } else {
                    p2 -> next = head;
                    p2 = head;
                }
            }
            
            head = head -> next;
        }
        
        if(l1) p1 -> next = l2;
        else l1 = l2;
        if(p2) p2 -> next = nullptr;
        
        return l1;
    }
};
