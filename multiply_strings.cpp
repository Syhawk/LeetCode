//uri:	https://leetcode.com/problems/multiply-strings/

/*
 *	大数相乘。预先为返回的字符串分配足够的字符'0'，以后便不会再考虑字符串增长。
 *	逆序从最低位循环计算，并存储结果，这样方便计算。
 *	空间复杂度：O(n * m).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size())
            swap(num1, num2);
        
        int len1 = num1.size();
        int len2 = num2.size();
        int len = len1 * len2 + 1;
        string re(len, '0');
        
        for(int i = len1 - 1; i >= 0; -- i) {
            int k = len1 - 1 - i;
            int flg = 0;
            int x = num1[i] - '0';
            for(int j = len2 - 1; j >= 0; -- j) {
                flg += x * (num2[j] - '0');
                re[k] += flg % 10;
                flg /= 10;
                if(re[k] > '9') {
                    re[k] -= 10;
                    flg += 1;
                }
                ++ k;
            }
            
            while(flg) {
                re[k] += flg;
                flg /= 10;
                if(re[k] > '9') {
                    re[k] -= 10;
                    flg += 1;
                }
                ++ k;
            }
        }
        
        while(re[len - 1] == '0' && len > 1) {
            re.erase(re.end() - 1);
            -- len;
        }
        
        for(int i = 0, j = len - 1; i < j; ++ i, -- j) {
            swap(re[i], re[j]);
        }
        
        return re;
    }
};
