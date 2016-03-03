//uri:	https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
 *	两个链表存在相同的节点必然是从两个链表的尾后开始的，由于两个链表的长度不一定
 *	相同，所以，按照较短的链表进行裁剪，然后同时往后遍历，查找两个链表的节点是否
 *	相同。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        if(lenA > lenB) {
            for(int i = lenA - lenB; i > 0; -- i)
                headA = headA -> next;
        } else {
            for(int i = lenB - lenA; i > 0; -- i)
                headB = headB -> next;
        }
        
        while(headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return headA;
    }
    
    int getLength(ListNode* root) {
        int len = 0;
        while(root) {
            root = root -> next;
            len += 1;
        }
        
        return len;
    }
};
