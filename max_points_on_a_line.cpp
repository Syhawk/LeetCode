//uri:	https://leetcode.com/problems/max-points-on-a-line/

/*
 *	遍历所有可能的情况，由于存在相同的点，所以采用一个标记数组进行标记。对于斜率无法大的情况特殊处理。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n^2).
 * */

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int _max = 0;
        vector<bool> same(points.size(), 0);
        for ( int i = 0; i < points.size(); ++ i ) {
            if ( same[i] ) { continue; }
            unordered_map<double, int> _map;
            int cnt_ver = 0;
            int cnt_same = 1;
            
            for ( int j = i + 1; j < points.size(); ++ j ) {
                if ( points[i].x != points[j].x || points[i].y != points[j].y ) { continue; }
                same[j] = true;
                cnt_same += 1;
            }
            
            for ( int j = i + 1; j < points.size(); ++ j ) {
                if ( same[j] ) { continue; }
                
                long _y = long(points[i].y) - points[j].y;
                long _x = long(points[i].x) - points[j].x;
                if ( _x == 0 ) {
                    cnt_ver += 1;
                    continue;
                }
                
                double k = _y * 1.0 / _x;
                _map[k] += 1;
                
                _max = max(_max, _map[k] + cnt_same);
            }
            
            _max = max(_max, cnt_ver + cnt_same);
        }
        
        return _max;
    }
};
