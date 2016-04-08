//uri:	https://leetcode.com/problems/rectangle-area/

/*
 *	计算两个矩形所形成的面积，其中重叠部分的面积需要单独计算，由于重叠情况有多种，
 *	在此全都归结为存在重叠面积和不存在重叠面积两种情况：首先把所有可能会产生的点全都枚举出来；
 *	然后判断这些点是否均存在于两个矩形之中，如果存在，那么存储起来；最后，把存储起来的点的x坐标与y坐标提取出来，
 *	计算重叠面积。返回两个矩形面积和减去重叠面积（如果两个矩形不重叠，那么重叠面积和为零）。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class _Point {
public:
    int x;
    int y;
    _Point(int a, int b) : x(a), y (b) { }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<int> X = {A, C, E, G};
        vector<int> Y = {B, D, F, H};
        vector<_Point> v;
        for(int i = 0; i < 4; ++ i) {
            for(int j = 0; j < 4; ++ j) {
                if(judge(X[i], Y[j], X, Y)) { v.push_back(_Point(X[i], Y[j])); }
            }
        }
        
        int cover = 0;
        if(v.size()) {
            int x1 = v[0].x;
            int x2 = v[0].x;
            int y1 = v[0].y;
            int y2 = v[0].y;
            for(int i = v.size() - 1; i > 0; -- i) {
                if(x1 == x2) { x2 = v[i].x; }
                if(y1 == y2) { y2 = v[i].y; }
            }
            
            cover = area(x1 - x2, y1 - y2);
        }
        
        return area(X[0] - X[1], Y[0] - Y[1]) + area(X[2] - X[3], Y[2] - Y[3]) - cover;
    }
    
    int area(int x, int y) { return abs(x * y); }
    
    bool judge(int x, int y, vector<int>& X, vector<int>& Y) {
        if(x < X[0] || x > X[1] || x < X[2] || x > X[3]) { return false; }
        if(y < Y[0] || y > Y[1] || y < Y[2] || y > Y[3]) { return false; }
        
        return true;
    }
};
