//uri:	https://leetcode.com/problems/rotate-list/

/*
 *	首先对k mod 链表长度（k有可能会大于链表长度）。然后将头节点指针右移到第k个节点
 *	，得到该节点指针；头节点指针与该节点指针同时右移，直至该节点指针变为空指针。
 *	这样就把该链表分为了两个链表，最后拼接起来，返回新的头节点指针。
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k < 1) return head;
        
        ListNode* pre = nullptr;
        ListNode* ptr = head;
        ListNode* newHead = head;
        
        int len = 0;
        while(ptr) {
            len += 1;
            ptr = ptr -> next;
        }
        
        k %= len;
        if(k < 1) return head;
        ptr = head;
        
        while(k -- && ptr) {
           ptr = ptr -> next;
        }
        
        if(ptr == nullptr) return newHead;
        
        while(ptr -> next) {
            pre = newHead;
            newHead = newHead -> next;
            ptr = ptr -> next;
        }
        
        pre = newHead;
        newHead = newHead -> next;
        pre -> next = nullptr;
        ptr -> next = head;
        
        return newHead;
    }
};
