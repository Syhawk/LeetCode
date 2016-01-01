//uri:	https://leetcode.com/problems/add-binary/

/*
 *	实现对两个二进制数相加的操作，最高位在字符串头部，最低位在字符串末位。
 *	空间复杂度：O(max(n, m)).
 *	时间复杂度：O(max(n, m)).
 * */

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1, j = b.size() - 1, k = 0;
        int flg = 0;
        
        while(i >= 0 || j >= 0 || flg) {
            s += '0' + flg;
            if(i >= 0) s[k] += a[i --] - '0';
            if(j >= 0) s[k] += b[j --] - '0';
            
            if(s[k] > '1') {
                flg = 1;
                s[k] -= 2;
            } else {
                flg = 0;
            }
            
            ++ k;
        }
        
        for( i = 0, j = k - 1; i < j; ++ i, -- j)
            swap(s[i], s[j]);
            
        return s;
    }
};
