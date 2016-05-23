//uri:	https://leetcode.com/problems/increasing-triplet-subsequence/

/*
 *	求最长上升子序列，如果这个子序列的长度>= 3，那么就返回true，否则返回false。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> seq;
        for ( int i = 0; i < nums.size() && seq.size() < 3; ++ i ) {
            if ( seq.size() < 1 || seq[seq.size() - 1] < nums[i] ) { seq.push_back(nums[i]); }
            else {
                int j = 0;
                for ( ; j < seq.size() && seq[j] < nums[i]; ++ j ) ;
                seq[j] = nums[i];
            }
        }
        
        return seq.size() >= 3;
    }
};
