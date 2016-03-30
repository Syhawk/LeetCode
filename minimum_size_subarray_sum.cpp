//uri:	https://leetcode.com/problems/minimum-size-subarray-sum/

/*
 *	求连续区间和 >= s 的最小区间，采用两个下标，分别表示区间的两端，每次满足区间和
 *	>= s 的时候，低下标往高下标方向移动，直至区间和 < s；然后高下标继续右移，扩大
 *	区间，满足区间和 >= s.
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        int pre = 0;
        int minSub = 0x7fffffff;
        for(int i = 0; i < len; ) {
            bool flg = false;
            while(sum < s && i < len) { sum += nums[i ++]; }
            
            if(sum >= s) { flg = true; }
            
            while(sum >= s && pre <= i) { sum -= nums[pre ++]; }
            
            if(flg) minSub = min(minSub, i - pre + 1);
        }
        
        return minSub == 0x7fffffff ? 0 : minSub;
    }
};
