//uri:	https://leetcode.com/problems/longest-increasing-subsequence/

/*
 *	用一个vector来记录当前最长上升子序列。遇到的元素值如果大于该子序列最大元素值，那么加入该子序列；
 *	否则从该子序列中查找第一个大于等于该元素值的第一个元素，然后替换。
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
 * */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        int len = nums.size();
        int lis_len = -1;
        for ( int i = 0; i < len; ++ i ) {
            if ( lis_len == -1 || nums[i] > lis[lis_len] ) {
                lis.push_back(nums[i]);
                ++ lis_len;
                continue;
            }
            
            int lhs = 0;
            int rhs = lis_len;
            while ( lhs < rhs ) {
                int mid = (lhs + rhs) >> 1;
                if ( lis[mid] == nums[i] ) {
                    rhs = mid;
                    break;
                }
                if ( lis[mid] < nums[i] ) { lhs = mid + 1; }
                else { rhs = mid; }
            }
            
            lis[rhs] = nums[i];
        }
        
        return lis_len + 1;
    }
};
