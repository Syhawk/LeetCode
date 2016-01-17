//uri:	https://leetcode.com/problems/subsets-ii/

/*
 *	找出所有子集，但是不能出现重复子集。采用深度优先遍历方式，在查找子集的时候
 *	进行元素重复判断。
 *	空间复杂度：O(2^n).
 *	时间复杂度：O(2^n).
 * */

inline bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        subs.clear();
        vector<int> v;
        
        dfs(0, nums, v);
        
        return subs;
    }
    
    void dfs(int index, vector<int>& nums, vector<int>& v) {
        subs.push_back(v);
        int len = nums.size();
        if(index >= len) return;
        
        for(int i = index; i < len; ++ i) {
            if(i != index && nums[i] == nums[i - 1]) continue;
            
            v.push_back(nums[i]);
            dfs(i + 1, nums, v);
            v.pop_back();
        }
    }
    
private:
    vector<vector<int>> subs;
};
