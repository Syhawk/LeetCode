//uri:	https://leetcode.com/problems/merge-two-sorted-lists/

/*
 *	将两个有序链表合并起来，新链表每次选取两个有序链表中当前节点值小的
 *	节点作为下一个元素，直到两个有序链表全都遍历完毕。
 *	空间复杂度：O(1).
 *	时间复杂度：O(m + n).
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2 == nullptr) return l1;
        if(l1 == nullptr) return l2;

        ListNode* head = l1;
        if(l1 -> val > l2 -> val) {
            head = l2;
            l2 = l2 -> next;
        } else l1 = l1 -> next;
        
        ListNode* ptr = head;
        while(l1 || l2) {
            if((l1 && !l2) || (l1 && l2 && l1 -> val <= l2 -> val)) {
                ListNode* tmp = l1 -> next;
                l1 -> next = nullptr;
                ptr -> next = l1;
                ptr = l1;
                l1 = tmp;
            }

            if((!l1 && l2) || (l1 && l2 && l2 -> val <= l1 -> val)) {
                ListNode* tmp = l2 -> next;
                l2 -> next = nullptr;
                ptr -> next = l2;
                ptr = l2;
                l2 = tmp;
            }
        }
        
        return head;
    }
};
