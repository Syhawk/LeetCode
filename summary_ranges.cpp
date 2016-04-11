//uri:	https://leetcode.com/problems/summary-ranges/

/*
 *	直接转换。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        int len = nums.size();
        for(int i = 0; i < len; ) {
            int j = i + 1;
            for( ; j < len && nums[j] - nums[j - 1] == 1; ++ j);
            
            string s = to_string(nums[i]);
            if(j - i > 1) { s += "->" + to_string(nums[j - 1]); }
            v.push_back(s);
            
            i = j;
        }
        
        return v;
    }
};
