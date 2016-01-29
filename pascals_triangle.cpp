//uri:	https://leetcode.com/problems/pascals-triangle/

/*
 *	按照规则，直接生成相应的数字即可。
 *	空间复杂度：O(n^2).
 *	时间复杂度：O(n^2).
 * */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows < 1) return v;
        
        vector<int> t;
        t.push_back(1);
        v.push_back(t);
        
        for(int i = 0; i < numRows - 1; ++ i) {
            int len = v[i].size();
            t.clear();
            for(int j = 0; j < len; ++ j) {
                if(j == 0) t.push_back(1);
                if(j) t.push_back(v[i][j - 1] + v[i][j]);
                if(j == len - 1) t.push_back(1);
            }
            
            v.push_back(t);
        }
        
        return v;
    }
};
