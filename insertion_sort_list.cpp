//uri:	https://leetcode.com/problems/insertion-sort-list/

/*
 *	要求采用插入排序的方法。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n^2).
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = nullptr;
        
        while(head) {
            ListNode* post = head -> next;
            if(newHead == nullptr) {
                newHead = head;
                newHead -> next = nullptr;
            } else {
                ListNode* ptr = newHead, *pre = nullptr;
                while(ptr && ptr -> val <= head -> val) {
                    pre = ptr;
                    ptr = ptr -> next;
                }
                
                if(pre == nullptr) {
                    head -> next = newHead;
                    newHead = head;
                } else {
                    pre -> next = head;
                    head -> next = ptr;
                }
            }
            
            head = post;
        }
        
        return newHead;
    }
};
