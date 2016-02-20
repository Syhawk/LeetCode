//uri:	https://leetcode.com/problems/single-number/

/*
 *	两个相同的数异或的结果为0.所以，将所有的元素亦或，最重的到得就是只出现一次的
 *	元素值。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; -- i)
            nums[0] ^= nums[i];
            
        return nums[0];
    }
};
