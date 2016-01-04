//uri:	https://leetcode.com/problems/single-number-iii/

/*
 *	两个数出现一次，剩余的数均出现2次。所以可以采用位运算亦或来解决问题。
 *	将所有的数亦或，得到的数事实上就是两个要返回的数。
 *	由于两个数不同，那么转换为二进制后，必然至少有一项2^x不同，此时一个数不存在
 *	这一项，一个数存在这一项。此时，我们可以根据这一项将所有的数分为两类，
 *	一类存在这一项，一类不存在这一项，分别进行异或，得到的两个数就是要返回的两个数
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> v;
        v.clear();
        if(len <= 0) return v;
        
        int x = 0;
        for(int i = 0; i < len; ++ i)
            x ^= nums[i];
            
        int c = 1;
        while(1) {
            if(x & c) break;
            else c *= 2;
        }
        
        int y = x;
        for(int i = 0; i < len; ++ i) {
            if(nums[i] & c) x ^= nums[i];
            else y ^= nums[i];
        }
        
        v.push_back(x);
        v.push_back(y);
        
        return v;
    }
};
