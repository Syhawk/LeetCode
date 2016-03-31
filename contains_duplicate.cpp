//uri:	https://leetcode.com/problems/contains-duplicate/

/*
 *	直接用unordered_map或者其他容器存储判别
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
 * */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> _map;
        for(int i = nums.size() - 1; i >= 0; -- i) {
            if(!_map[nums[i]]) { _map[nums[i]] = true; }
            else { return true; }
        }
        
        return false;
    }
};
