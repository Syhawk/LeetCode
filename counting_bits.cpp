//uri:	https://leetcode.com/problems/counting-bits/

/*
 *	当前元素所包含1的个数 = （当前元素值 - 当前元素所包含的最大2次幂）所包含的1的个数 + 1；
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(1);
        for ( int i = 1, base = 1, pre = 1; i <= num; ++ i ) {
            result.push_back(result[i - base] + 1);
            base -= 1;
            if ( base == 0 ) {
                pre <<= 1;
                base = pre;
            }
        }
        
        return result;
    }
};
