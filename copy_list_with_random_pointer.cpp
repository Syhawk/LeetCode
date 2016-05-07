//uri:	https://leetcode.com/problems/copy-list-with-random-pointer/

/*
 *	在每个节点后面拷贝一份当前节点，random指针均为空，链表长度就会变为原来的两倍。
 *	再次遍历链表，如果节点的random指针不为空，那么，下一个拷贝节点的random指针也应当不为空，假设当前节点指针为ptr，那么：
 *	ptr -> next -> random = ptr -> random -> next;
 *	ptr每次循环递增两次。
 *	最后，再遍历一次链表，把原始链表与深拷贝链表分离，且原始链表不能被修改。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* ptr = head;
        while ( ptr ) {
            RandomListNode* post = ptr -> next;
            ptr -> next = new RandomListNode(ptr -> label);
            ptr -> next -> next = post;
            ptr = post;
        }
        
        ptr = head;
        while ( ptr ) {
            if ( ptr -> random ) { ptr -> next -> random = ptr -> random -> next; }
            ptr = ptr -> next -> next;
        }
        
        RandomListNode* new_head = nullptr;
        RandomListNode* new_tail = nullptr;
        ptr = head;
        while ( ptr ) {
            RandomListNode* post = ptr -> next -> next;
            if ( new_head == nullptr ) { new_head = ptr -> next; }
            else { new_tail -> next = ptr -> next; }
            
            new_tail = ptr -> next;
            new_tail -> next = nullptr;
            
            ptr -> next = post;
            ptr = post;
        }
        
        return new_head;
    }
};
