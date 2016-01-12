//uri: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/*
 *	将所有重复的节点全部删除。
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head, *newHead = nullptr, *newNext = nullptr;
        while(head) {
            int cnt = 1;
            while((head = head -> next) && head -> val == pre -> val) {
                ++ cnt;
            }
            
            if(cnt > 1) {
                pre = head;
                continue;
            }
            
            if(newHead == nullptr) {
                newNext = pre;
                newHead = pre;
            } else {
                newNext -> next = pre;
                newNext = pre;
            }
            
            pre = head;
        }
        
        if(newNext) newNext -> next = nullptr;
        return newHead;
    }
};
