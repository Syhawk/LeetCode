//uri:	https://leetcode.com/problems/longest-consecutive-sequence/

/*
 *	用unordered_map来存储一个连续的区间，每插入一个元素，就查找能把这个元素归并进入的上区间和下区间
 *	然后合并这个区间，并把原来的区间删除掉。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> _map;
        int max_len = 0;
        for ( int i = 0; i < nums.size(); ++ i ) {
            if ( _map.find(nums[i]) != _map.end() ) { continue; }
            
            auto lhs = findInterval(_map, nums[i], -1);
            auto rhs = findInterval(_map, nums[i], 1);
    
            int left = min(lhs.first, rhs.first);
            int right = max(lhs.second, rhs.second);
            
            _map[left] = right;
            _map[right] = left;
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
    
    pair<int, int> findInterval(unordered_map<int, int>& _map, int val, int choose ) {
        auto p = _map.find(val + choose);
        if ( p == _map.end() ) { return make_pair(val, val); }
        
        pair<int, int> v = make_pair(min(p -> first, p -> second), max(p -> first, p -> second));
        _map.erase(v.first);
        _map.erase(v.second);

        return v;
    }
};
