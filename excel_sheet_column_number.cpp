//uri:	https://leetcode.com/problems/excel-sheet-column-number/

/*
 *	直接循环一次计算就好。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for(int i = 0; s[i]; ++ i)
            sum = sum * 26 - 'A' + 1 + s[i];
            
        return sum;
    }
};
