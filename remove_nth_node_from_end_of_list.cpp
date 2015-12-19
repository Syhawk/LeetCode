//uri:	https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
 *	为了只需要循环遍历一次就能删除倒数第n个结点，那么可以事先遍历到第n个结点。
 *	如果链表长度为n，那么头结点就是要删除的结点；如果链表长度大于n，那么
 *	当前的结点右移m位至尾结点，头结点也右移m位，所到达节点就是要删除的结点。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;
        ListNode* p = head;
        while(p) {
            if(n < 0) pre = pre -> next;
            p = p -> next;
            n -= 1;
        }
        
        if(n < 0)
            pre -> next = pre -> next -> next;
        else head = head -> next;
        return head;
    }
};
