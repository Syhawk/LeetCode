//uri:	https://leetcode.com/problems/subsets/

/*
 *	找出一个数组的所有可能的子集，直接暴力。
 *	空间复杂度：O(2^n).
 *	时间复杂度：O(2^n).
 * */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        v.clear();
        vector<int> t;
        
        sort(nums.begin(), nums.end());
        dfs(0, nums.size(), nums, t);
        
        return v;
    }
    
    void dfs(int index, int len, vector<int>&nums, vector<int>& t) {
        v.push_back(t);
        
        for(int i = index; i < len; ++ i) {
            t.push_back(nums[i]);
            dfs(i + 1, len, nums, t);
            t.pop_back();
        }
    }

private:
    vector<vector<int>> v;
};
