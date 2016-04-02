//uri:	https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
 *	根据规则直接转化即可。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1) { return head; }
        
        ListNode* ptr = head;
        ListNode* newHead = nullptr, *newTail = nullptr;
        while(ptr) {
            ListNode* pre = ptr;
            ListNode* tail = ptr;
            
            int t = k;
            while(t -- && ptr) { ptr = ptr -> next; }
            
            if(t == -1) {
                ListNode* rev = nullptr;
                while(pre != ptr) {
                    ListNode* post = pre -> next;
                    pre -> next = rev;
                    rev = pre;
                    pre = post;
                }
                
                pre = rev;
            }
            
            if(newHead == nullptr) { newHead = pre; }
            if(newTail) { newTail -> next = pre; }
            newTail = tail;
        }
        
        return newHead;
    }
};
