//uri:	https://leetcode.com/problems/recover-binary-search-tree/

/*
 *	BST中序遍历得到的序列的元素值是递增的，所以，可以通过中序遍历来判断交换位置的两个元素。
 *	用mistake1和mistake2来表示第一次出现错误的两个元素节点的指针，其中，mistake1表示前一个元素节点指针；
 *	继续遍历，如果出现了第二次错误交换的两个元素节点，说明错误交换发生在两个不相邻节点，
 *	那么把mistake2赋值为此次错误节点指针的后一个节点指针；否则，错误交换发生在两个相邻节点，即第一次出现错误的两个元素节点指针。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        auto pre = root;
        while ( root ) {
            st.push(root);
            pre = root;
            root = root -> left;
        }
        
        TreeNode* mist1 = nullptr;
        TreeNode* mist2 = nullptr;
        
        while ( !st.empty() ) {
            auto p = st.top();
            st.pop();
            
            if ( pre -> val > p -> val ) {
                if ( mist1 == nullptr ) {
                    mist1 = pre;
                    mist2 = p;
                } else {
                    mist2 = p;
                    break;
                }
            }
            
            pre = p;
            p = p -> right;
            while( p ) {
                st.push(p);
                p = p -> left;
            }
        }
        
        swap(mist1 -> val, mist2 -> val);
    }
};
