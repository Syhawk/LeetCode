//uri:	https://leetcode.com/problems/pascals-triangle-ii/

/*
 *	按照规则直接生成
 *	空间复杂度：O(n).
 *	时间复杂度：O(n^2).
 * */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if(rowIndex < 0) return v;
        
        v.push_back(1);
        vector<int> t;
        for(int i = 0; i < rowIndex; ++ i) {
            int len = v.size();
            t.clear();
            
            for(int j = 0; j < len; ++ j) {
                if(j == 0) t.push_back(1);
                if(j) t.push_back(v[j - 1] + v[j]);
                if(j == len - 1) t.push_back(1);
            }
            v = t;
        }
        
        return v;
    }
};
