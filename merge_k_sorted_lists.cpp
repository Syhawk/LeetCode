//uri:	https://leetcode.com/problems/merge-k-sorted-lists/

/*
 *	采用分治的思想，每次对两个list进行排序，然后从递归形式转化为非递归形式来减少时耗。
 *	空间复杂度：O(1).
 *	时间复杂度：O(max(m)log(n)).
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) { return nullptr; }
        
        int t = 1;
        int r = 2;
        while(t < len) {
            for(int i = 0; i + t < len; i += r) { lists[i] = mergeLists(lists[i + t], lists[i]); }
            
            t = r;
            r <<= 1;
        }
        
        return lists[0];
    }
    
    ListNode* mergeLists(ListNode* lhs, ListNode* rhs) {
        if(lhs == nullptr) { return rhs; }
        if(rhs == nullptr) { return lhs; }
        
        ListNode* newHead = nullptr, *tail = nullptr;
        while(lhs && rhs) {
            ListNode* ptr = minListNode(lhs, rhs);
            if(newHead == nullptr) { newHead = ptr; }
            else { tail -> next = ptr; }
            
            tail = ptr;
            tail -> next = nullptr;
        }
        
        if(lhs) { tail -> next = lhs; }
        else { tail -> next = rhs; }
        
        return newHead;
    }
    
    ListNode* minListNode(ListNode*& lhs, ListNode*& rhs) {
        ListNode* ptr = nullptr;
        if(lhs -> val <= rhs -> val) {
            ptr = lhs;
            lhs = lhs -> next;
        } else {
            ptr = rhs;
            rhs = rhs -> next;
        }
        
        return ptr;
    }
};
