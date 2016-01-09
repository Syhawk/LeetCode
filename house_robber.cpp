//uri:	https://leetcode.com/problems/house-robber/

/*
 *	由于不能抢劫临近的房屋，所以采用动归来解决：
 *	dp(i) = max(dp(i - 1), dp(i - 2) + nums[i])
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int money = 0;
        for(int i = 0; i < len; ++ i) {
            if(i - 3 >= 0)
                nums[i] += max(nums[i - 2], nums[i - 3]);
            else if(i == 2)
                nums[i] += nums[i - 2];
                
            money = max(nums[i], money);
        }
        
        return money;
    }
};
