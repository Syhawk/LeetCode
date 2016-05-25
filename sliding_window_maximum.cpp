//uri:	https://leetcode.com/problems/sliding-window-maximum/

/*
 *	维护一个递减双端队列，这个双端队列存储的是元素下标，其所对应的元素为递减序列。
 *	如果遇到的元素值大于当前最小元素值，那么，把其下标插入队尾，否则就循环删除队尾元素下标，直至满足条件为止。
 *	如果队列头部元素下标在k的元素下标之外，那么删除该元素下标。
 *	空间复杂度：O(k).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> result;
        for ( int i = 0; i < nums.size(); ++ i ) {
            while ( !window.empty() && nums[window.back()] <= nums[i] ) { window.pop_back(); }
            window.push_back(i);
            if ( window.front() <= i - k ) { window.pop_front(); }
            
            if ( i >= k - 1 ) { result.push_back(nums[window.front()]); }
        }
        
        return result;
    }
};
