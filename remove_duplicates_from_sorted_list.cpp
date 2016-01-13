//uri:	https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
 *	删除重复元素，只保留一个
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* newHead = head, *ptr = head;
        while(head = head -> next) {
            if(head -> val == ptr -> val) continue;
            ptr -> next = head;
            ptr = head;
        }
        ptr -> next = nullptr;
        
        return newHead;
    }
};
