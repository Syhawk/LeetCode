//uri:	https://leetcode.com/problems/patching-array/

/*
 *	取sum为缺失的最小数值。遍历数组，如果遇到的数值小于sum，那么，sum += nums[i]，表示所缺失的最小数值为 sum + nums[i]。
 *	否则，表示sum与该数值之间存在跨度，无法用sum来表示出nums[i]，那么可以把sum数值加倍，表示添加一个值为sum的patch。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int min_patch = 0;
        long sum = 1;
        for ( int i = 0; sum <= n; ) {
            if ( i < nums.size() && nums[i] <= sum ) { sum += nums[i ++]; }
            else {
                sum += sum;
                min_patch += 1;
            }
        }
        
        return min_patch;
    }
};
