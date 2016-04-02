//uri:	https://leetcode.com/problems/contains-duplicate-iii/

/*
 *	由于数组可能存在重复元素，所以采用multiset，升序排序，元素多于（k + 1）
 *	个时，就删除最早加入multiset中的元素；每次查找大于等于当前元素值以及小于
 *	当前元素值的两个元素，判断差距是否在t之内。
 *	空间复杂度：O(k).
 *	时间复杂度：O(nlog(k)).
 * */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> _set;
        for(int i = nums.size() - 1, j = k; i >= 0; -- i) {
            auto p = _set.upper_bound(nums[i]);
            if( (p != _set.end() && abs((long)nums[i] - *p) <= t) || (p != _set.begin() && abs(*(-- p) - (long)nums[i]) <= t) ) { return true; }
            
            _set.insert(nums[i]);
            
            if(j) { -- j; }
            else { _set.erase(_set.find(nums[i + k])); }
        }
        
        return false;
    }
};
