//uri:	https://leetcode.com/problems/odd-even-linked-list/

/*
 *	将链表拆分成两部分，然后组合在一块。
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = nullptr;
        ListNode* odd_tail = nullptr;
        ListNode* even = nullptr;
        ListNode* even_tail = nullptr;
        
        int cnt = 1;
        while ( head ) {
            ListNode* post = head -> next;
            
            if ( cnt & 1 ) { insert(odd, odd_tail, head); }
            else { insert(even, even_tail, head); }
            
            cnt += 1;
            head = post;
        }
        
        if ( odd_tail ) { odd_tail -> next = even; }
        if ( even_tail ) { even_tail -> next = nullptr; }
        
        return odd;
    }
    
    void insert(ListNode*& head, ListNode*& tail, ListNode*& node) {
        if ( head == nullptr ) {
            head = node;
            tail = node;
        } else {
            tail -> next = node;
            tail = tail -> next;
        }
    }
};
