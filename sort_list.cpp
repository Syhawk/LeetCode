//uri:	https://leetcode.com/problems/sort-list/

/*
 *	借用快排的方式进行排序：每次选取链表第一个节点为基点，把链表拆分成大于此基点、
 *	小于此基点和等于此基点的三个链表。然后分别对大于此基点和小于此基点的链表进行
 *	上一步的操作。最后，将返回的链表按照大小次序组合起来即可。
 *	空间复杂度：O(1).
 *	时间复杂度：O(nlogn).
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* lhs = nullptr;
        ListNode* rhs = nullptr;
        ListNode* mhs = nullptr;
        ListNode* tmp = head;
        while(head) {
            ListNode* post = head -> next;
            if(head -> val < tmp -> val) {
                head -> next = lhs;
                lhs = head;
            } else if(head -> val > tmp -> val) {
                head -> next = rhs;
                rhs = head;
            } else {
                head -> next = mhs;
                mhs = head;
            }
            head = post;
        }
        
        lhs = sortList(lhs);
        rhs = sortList(rhs);
        
        tmp -> next = rhs;
        rhs = mhs;
        
        if(lhs == nullptr) 
            return rhs;
        ListNode* tail = lhs;
        while(tail -> next)
            tail = tail -> next;
        tail -> next = rhs;
        
        return lhs;
    }
};
