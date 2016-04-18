//uri:	https://leetcode.com/problems/palindrome-linked-list/

/*
 *	计算出链表的长度，将链表从中间平分为两条新的链表，将第二条链表进行反转，两条链表进行对比。
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
    bool isPalindrome(ListNode* head) {
        if ( head == nullptr ) { return true; }
        
        ListNode* ptr = head;
        int len = 1;
        while ( ptr ) {
            ++ len;
            ptr = ptr -> next;
        }
        
        len >>= 1;
        ptr = head;
        while ( len -- ) { ptr = ptr -> next; }
        
        ListNode* newHead = nullptr;
        while ( ptr ) {
            ListNode* post = ptr -> next;
            ptr -> next = newHead;
            newHead = ptr;
            ptr = post;
        }
        
        while ( newHead ) {
            if ( head -> val != newHead -> val ) { return false; }
            
            head = head -> next;
            newHead = newHead -> next;
        }
        
        
        return true;
    }
};
