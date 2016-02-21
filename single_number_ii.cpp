//uri:	https://leetcode.com/problems/single-number-ii/

/*
 *	将数组内所有元素转换成二进制，对二进制的每一位进行统计，统计的每一位如果能够
 *	被3整除，那么只出现一次的元素必不包含该位；否则，包含该位。最后把所有包含的位
 *	相加。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < 32; ++ i) {
            int bit = 1 << i;
            int cnt = 0;
            for(int j = nums.size() - 1; j >= 0; -- j) {
                if(bit & nums[j]) cnt += 1;
            }
            if(cnt % 3) x += bit;
        }
        
        return x;
    }
};
