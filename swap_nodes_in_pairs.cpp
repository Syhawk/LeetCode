//uri:	https://leetcode.com/problems/swap-nodes-in-pairs/

/*
 *	每两个节点进行交换。为了增加交换速度，只交换节点指针，而不交换其内在属性值。
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head -> next == NULL) return head;
        
        ListNode* nHead = head -> next;
        
        ListNode* pre = head;
        ListNode* prep = NULL;
        head = head -> next;
        while(head) {
            ListNode* post = head -> next;
            head -> next = pre;
            pre -> next = post;
            if(prep)
                prep -> next = head;
            
            prep = pre;
            pre = post;
            
            if(!post) break;
            head = post -> next;
        }
        
        return nHead;
    }
};
