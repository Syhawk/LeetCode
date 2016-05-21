//uri:	https://leetcode.com/problems/the-skyline-problem/

/*
 *	把建筑物轮廓分为两部分(Li, Hi), (Ri, Hi),这两部分都是按照Li < Li + 1, Li == Li + 1 && Hi < Hi + 1排序(即位置递增，如果位置相同，高度递增)
 *	并用一个multiset存储Li遍历过的高度Hi。
 *	遍历数组，选择Li, Rj中较小的一个下标以及所对应的数组。
 *	如果Li较小。(Li, Hi)中的Hi大于当前的高度H，那么最大高度H就更新为当前Li位置处的最大高度，并把(Li, H)加入要返回的vector中。把Hi加入multiset
 *	如果Rj较小。删除Hj在multiset中所对应的一个迭代器。根据multiset更新最大H，如果最大H有变化，就把(Rj, H)加入要返回的vector中。
 *	空间复杂度：O(n).
 *	时间复杂度：O(nlon).
 * */

inline bool cmp(const pair<int, int>& p, const pair<int, int>& q ) {
    if ( p.first != q.first ) { return p.first < q.first; }
    return p.second < q.second;
}

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> rhs;
        vector<pair<int, int>> result;
        
        for ( int i = 0; i < buildings.size(); ++ i ) { rhs.push_back(make_pair(buildings[i][1], buildings[i][2])); }
        
        sort(rhs.begin(), rhs.end(), cmp);
        multiset<int, greater<int>> heigh;
        int _h = 0;
        
        for ( int l = 0, r = 0; l < buildings.size() || r < rhs.size(); ) {
            if ( (l < buildings.size() && r < rhs.size() && buildings[l][0] <= rhs[r].first) || (r >= rhs.size() && l < buildings.size()) ) {
                int x = buildings[l][0];
                int y = buildings[l][2];
                while ( l < buildings.size() && x == buildings[l][0] ) {
                    y = max(y, buildings[l][2]);
                    heigh.insert(buildings[l ++][2]);
                }
                
                if ( _h < y ) {
                    result.push_back(make_pair(x, y));
                    _h = y;
                }
                continue;
            }
            
            heigh.erase(heigh.find(rhs[r].second));
            
            auto itr = heigh.begin();
            int x = (itr == heigh.end()) ? 0 : (*itr);
            if ( x < _h ) {
                _h = x;
                result.push_back(make_pair(rhs[r].first, x));
            }

            ++ r;
        }
        
        return result;
    }
};
