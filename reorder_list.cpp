//uri:	https://leetcode.com/problems/reorder-list/

/*
 *	将链表分为两部分，然后再按照规则组合起来。
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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        
        ListNode* l1_head = head;
        ListNode* l2_head = nullptr;
        ListNode* ptr = head;
        
        int cnt = 0;
        while(ptr) {
            ptr = ptr -> next;
            ++ cnt;
        }
        
        cnt = (cnt + 1) >> 1;
        ptr = head;
        while(-- cnt) {
            ptr = ptr -> next;
        }
        
        ListNode* l1_tail = ptr;
        ptr = ptr -> next;
        l1_tail -> next = nullptr;
        
        while(ptr) {
            ListNode* post = ptr -> next;
            ptr -> next = l2_head;
            l2_head = ptr;
            ptr = post;
        }
        
        while(l1_head && l2_head) {
            ListNode* l1_post = l1_head -> next;
            ListNode* l2_post = l2_head -> next;
            
            l1_head -> next = l2_head;
            l2_head -> next = l1_post;
            
            l1_head = l1_post;
            l2_head = l2_post;
        }
    }
};
