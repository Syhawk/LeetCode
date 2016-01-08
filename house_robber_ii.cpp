//uri:	https://leetcode.com/problems/house-robber-ii/

/*
 *	所有房屋圈成了一个环，那么就可以把[0, n - 1]分为两部分[0, n - 2]和[1, n - 1]
 *	分别求取最大值，选出最大的一个。每一部分采用动归求解：
 *	dp(i) = max(dp(i - 1), dp(i - 2) + num(i)).
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        if(len == 1) return nums[0];
        vector<int> v1 = {0, 0};
        vector<int> v2 = {0, 0, 0};
        
        for(int i = 0, j = 2; i < len; ++ i, ++ j) {
            if(i < len - 1) {
                int t = max(v1[j - 1], v1[j - 2] + nums[i]);
                v1.push_back(t);
            }
            if(i == 0) continue;
            int t = max(v2[j - 1], v2[j - 2] + nums[i]);
            v2.push_back(t);
        }
        
        return max(v1[v1.size() - 1], v2[v2.size() - 1]);
    }
};
