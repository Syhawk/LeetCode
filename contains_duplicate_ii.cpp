//uri:	https://leetcode.com/problems/contains-duplicate-ii/

/*
 *	采用一个unordered_set来存储连续的k + 1个元素，然后每次删除区间最后一个元素并添加最新的元素。
 *	空间复杂度：O(k).
 *	时间复杂度：O(nlog(k)).
 * */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k += 1;
        unordered_set<int> _set;
        for(int i = nums.size() - 1, t = k; i >= 0; -- i) {
            if(t == 0) { _set.erase(nums[i + k]); }
            if(_set.find(nums[i]) != _set.end()) { return true; }
            _set.insert(nums[i]);
            
            if(t) -- t;
        }
        
        return false;
    }
};
