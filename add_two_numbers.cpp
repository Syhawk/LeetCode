//uri:	https://leetcode.com/problems/add-two-numbers/

/*
 *	首先判断两个链表是否为空，若存在一个链表为空，直接返回。
 *	两个链表均不为空时，以l1链表为基准，讲l2链表上的数值加到
 *	l1上面，返回链表l1.
 *	空间复杂度：O(1).
 *	时间复杂度：O(max(n, m)).
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1) return add(l1, l2);
        return add(l2, l1);            
    }
    
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* pre = nullptr;
        int x = 0;
        while(l1 || l2 || x) {
            if(l1) pre = l1;
            int y = x;
            if(l1) y += l1 -> val;
            if(l2) y += l2 -> val;
            x = y / 10;
            if(!l1 && !l2) pre -> next = new ListNode(y);
            else if(!l1 && l2) {
                pre -> next = l2;
                pre = l2;
                l2 -> val = y % 10;
                if(x == 0) break;
            } else if(l1 && !l2) {
                l1 -> val = y % 10;
                if(x == 0) break;
            } else l1 -> val = y % 10;
            
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        return p;
    }
};
