//uri:	https://leetcode.com/problems/gray-code/

/*
 *	将n位二进制数转换为格雷码：Gi = Bi xor B(i - 1)
 *	空间复杂度：O(2^n).
 *	时间复杂度：O(2^n).
 * */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        int len = 1 << n;
        for(int i = 0; i < len; ++ i) {
            v.push_back(i ^ (i >> 1));
        }
        
        return v;
    }
};
