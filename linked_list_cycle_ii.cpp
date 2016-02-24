//uri:	https://leetcode.com/problems/linked-list-cycle-ii/

/*
 *	采用大步小步算法：两个链表指针均从链表头部往后移，第一个指针每次移一步，
 *	第二个指针每次移两步，直至其中一个指针为空或者两个指针相同时结束。
 *	如果链表存在环，那么再采用两个指针，一个指针从头节点往后移，一个指针从上一步
 *	终止位置往后移，直至两个指针相同时结束，返回该节点。
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* ptr = head;
        ListNode* qtr = head;
        while(ptr) {
            ptr = ptr -> next;
            if(ptr == nullptr) return ptr;
            ptr = ptr -> next;
            qtr = qtr -> next;
            
            if(ptr == qtr) break;
        }
        
        if(ptr == nullptr) return ptr;
        
        while(ptr != head) {
            ptr = ptr -> next;
            head = head -> next;
        }
        
        return ptr;
    }
};
