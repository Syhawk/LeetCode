//uri:	https://leetcode.com/problems/missing-number/

/*
 *	线性时间解决问题，只能借助常量空间。由于n个数均不相同，而且其值的范围都是
 *	[0, n]，所以采用递增队列求和公式求和，然后减去每一个元素，最后得到的值就是
 *	缺少的元素。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (len + 1) * len / 2;
        
        for(int i = 0; i < len; ++ i)
            sum -= nums[i];
            
        return sum;
    }
};
