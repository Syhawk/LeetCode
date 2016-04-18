//uri:	https://leetcode.com/problems/merge-intervals/

/*
 *	对每个区间进行排序：以区间开始位置为第一关键字升序排序，如果第一关键字相同，则把区间结束位置作为第二关键字升序排序。
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlogn).
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

inline bool cmp(const Interval& p, const Interval& q) {
    if (p.start != q.start) { return p.start < q.start; }
    return p.end < q.end;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int len = intervals.size();
        vector<Interval> result;
        int ptr = -1;
        for (int i = 0; i < len; ++ i) {
            if (ptr == -1 || result[ptr].end < intervals[i].start) {
                result.push_back(intervals[i]); 
                ++ ptr;
                continue;
            }
            
            result[ptr].end = max(result[ptr].end, intervals[i].end);
        }
        
        return result;
    }
};
