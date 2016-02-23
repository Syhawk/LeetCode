//uri:	https://leetcode.com/problems/linked-list-cycle/

/*
 *	通过使用大步小步方式来判别是否存在环：使用两个指针同时从头节点开始往后遍历，
 *	其中一个指针每次后移一步，另一个节点每次后移两步，直至遍历到尾节点或者两个指针
 *	所值节点相同时结束。
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* ptr = head -> next;
        while(ptr) {
            if(ptr == head) return true;
            
            ptr = ptr -> next;
            if(ptr == nullptr) break;
            ptr = ptr -> next;
            head = head -> next;
        }
        
        return false;
    }
};
