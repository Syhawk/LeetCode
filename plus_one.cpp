//uri:	https://leetcode.com/problems/plus-one/

/*
 *	用一个数组表示一个大数，大数最高位在数组的头部，大数最低位在数组尾部。
 *	把这个大数的值加1并输出。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        int cnt = 1;
        
        for(int i = digits.size() - 1; i >= 0; -- i ) {
            cnt += digits[i];
            v.push_back(cnt % 10);
            cnt /= 10;
        }
        
        while(cnt) {
            v.push_back(cnt % 10);
            cnt /= 10;
        }
        
        for(int i = 0, j = v.size() - 1; i < j; ++ i, -- j)
            swap(v[i], v[j]);
            
        return v;
    }
};
