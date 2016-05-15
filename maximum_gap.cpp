//uri:	https://leetcode.com/problems/maximum-gap/

/*
 *	思路：数组内排序之后邻近的两个数的差值一定满足条件：max_gap >= (_max - _min) / (nums.size() - 1).
 *	基于此，将数组nums分为num.size()个桶，每一份维护一个最大值，一个最小值，并将其值按照对应的转化下标放到对应的桶中。
 *	转化下标公式为：(nums[i] - _min) / gap;
 *	
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if ( nums.size() < 1 ) { return 0; }
        
        int _max = nums[0];
        int _min = nums[0]; 
        for ( int i = 1; i < nums.size(); ++ i ) {
            _max = max(_max, nums[i]);
            _min = min(_min, nums[i]);
        }
        
        int gap = (_max - _min) / nums.size() + 1;
        vector<int> max_pair(nums.size(), -1);
        vector<int> min_pair(nums.size(), 0x7fffffff);
        
        for ( int i = 0; i < nums.size(); ++ i ) {
            int index = (nums[i] - _min) / gap;
            
            max_pair[index] = max(max_pair[index], nums[i]);
            min_pair[index] = min(min_pair[index], nums[i]);
        }
        
        int max_gap = 0;
        for ( int i = 0; i < nums.size(); ++ i ) {
            if ( max_pair[i] == -1 ) { continue; }
            
            max_gap = max(max_gap, max_pair[i] - min_pair[i]);
            max_gap = max(max_gap, min_pair[i] - _min);
            _min = max_pair[i];
        }
        
        return max_gap;
    }
};
