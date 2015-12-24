//uri:	https://leetcode.com/problems/maximum-subarray/

/*
 *	查找一个数组的最大连续和，可以采用动归，也可以采用贪心的方式。
 *	以下代码采用贪心，y每次选取最大的值，如果选取时发现当前累加和x小于0，就将该
 *	选取的值赋给x。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int x = 0, y = nums[0];
        for(int i = 0; i < len; ++ i) {
            if(x <= 0)
                x = nums[i];
            else x += nums[i];
            y = max(y, x);
        }
        
        return y;
    }
};
