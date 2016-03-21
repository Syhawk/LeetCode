//uri:	https://leetcode.com/problems/remove-linked-list-elements/

/*
 *	遍历链表，遇到目标元素值直接删除。
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;
        while(head) {
            ListNode* post = head -> next;
            if(head -> val != val) {
                if(newHead == nullptr) { newHead = head; }
                else { newTail -> next = head; }
                
                newTail = head;
                newTail -> next = nullptr;
            }
            
            head = post;
        }
        
        return newHead;
    }
};
