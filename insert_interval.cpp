//uri:	https://leetcode.com/problems/insert-interval/

/*
 *	我们把newInterval插入到intervals中，然后对其排序，因为本来就是有序的，插入一个Interval相当于是插入排序。
 *	然后我们再合并重叠区间。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        int len = intervals.size();
        for ( int i = len - 2; i >= 0; -- i ) {
            if ( intervals[i].start > intervals[i + 1].start ) { swap(intervals[i], intervals[i + 1]); }
            else if ( intervals[i].start == intervals[i + 1].start && intervals[i].end > intervals[i + 1].end ) {
                swap(intervals[i], intervals[i + 1]);
            } else { break; }
        }
        
        int k = 0;
        for ( int i = 1; i < len; ++ i ) {
            if ( intervals[k].end < intervals[i].start ) { intervals[++ k] = intervals[i]; }
            else { intervals[k].end = max(intervals[k].end, intervals[i].end); }
        }
        
        for ( ++ k; len > k; -- len) { intervals.pop_back(); }
        
        return intervals;
    }
};
