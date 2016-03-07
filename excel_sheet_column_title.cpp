//uri:	https://leetcode.com/problems/excel-sheet-column-title/

/*
 *	将数字转换成字母时，注意0代表什么。
 *	空间复杂度：O(log26(n)).
 *	时间复杂度：O(log26(n)).
 * */

class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n) {
            int x = n % 26;
            s += 'A' + (x + 25) % 26;
            n = (n - 1) / 26;
        }
        
        for(int i = 0, j = s.size() - 1; i < j; ++ i, -- j)
            swap(s[i], s[j]);
        
        return s;
    }
};
