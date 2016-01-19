https://leetcode.com/problems/reverse-linked-list-ii/

/*
 *	将链表分为三部分，然后对中间部分进行逆转，最后拼接起来
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ptr = head, *pre = nullptr;
        ListNode *newHead = nullptr, *tail = nullptr;
        
        m -= 1;
        n -= 1;
        
        for(int i = 0; i < m; ++ i) {
            pre = ptr;
            ptr = ptr -> next;
        }
        
        for(int i = m; i <= n; ++ i) {
            ListNode* tmp = ptr;
            ptr = ptr -> next;
            tmp -> next = newHead;
            newHead = tmp;
            if(i == m) tail = newHead;
        }
        
        tail -> next = ptr;
        if(pre) {
            pre -> next = newHead;
            return head;
        }
        
        return newHead;
    }
};
