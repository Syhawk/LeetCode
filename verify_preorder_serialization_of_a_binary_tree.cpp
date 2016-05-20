//uri:	https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

/*
 *	根据前序遍历的顺序，用栈进行模拟，然后再把栈去掉，用一个变量表示。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int height = 1;
        for ( int i = 0; i < preorder.size(); ++ i ) {
            if ( isdigit(preorder[i]) ) {
                if ( height == 0 ) { return false; }
                height += 1;
                while ( isdigit(preorder[i]) ) {  ++ i; }
            } else {
                if ( height == 0 ) { return false; }
                height -= 1;
                ++ i;
            }
        }
        
        return (height == 0);
    }
};
