//uri:	https://leetcode.com/problems/product-of-array-except-self/

/*
 *	由于要返回的输出vector不算是额外的空间，所以，我们可以借助这个vector实现不用除法的乘积：
 *	当前乘积 = 左边的乘积 * 右边的乘积。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> proArray = {nums[0]};
        int len = nums.size();
        for ( int i = 1; i < len; ++ i ) { proArray.push_back(proArray[i - 1] * nums[i]); }
        int pro = 1;
        for ( int i = len - 1; i >= 0; -- i ) {
            if ( i ) { proArray[i] = proArray[i - 1] * pro; }
            else { proArray[i] = pro; }
            pro *= nums[i];
        }
        
        return proArray;
    }
};
