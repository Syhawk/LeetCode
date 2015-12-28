//uri:	https://leetcode.com/problems/spiral-matrix-ii/

/*
 *	实现起来比较麻烦一点。由于需要存储起来，如果仅用vector，那么要比c语言的数组
 *	要麻烦的多。首先，将要存储的行分为从上到下的行和从下到上的行，这是由于每实现
 *	一次外围循环，就会出现两行、两列，两列没法存储于vector中，除非你事先申请
 *	好vector是n*n的。那么，我们可以把两行分别存储起来，然后再通过两行的信息得出
 *	这两行中间其他行的元素信息。
 *	空间复杂度：O(n*n).
 *	时间复杂度：O(n*n).
 * */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> utod;
        vector<vector<int>> dtou;
        if(n < 1) return utod;
        if(n == 1) return {{1}};
        
        vector<int> tmp;
        for(int i = 1; i <= n; ++ i)
            tmp.push_back(i);
        utod.push_back(tmp);
        for(int i = (n - 1) * 3 + 1, j = 0; i > (n - 1) * 2; -- i, ++ j)
            tmp[j] = i;
        dtou.push_back(tmp);
        
        for(int i = 2; i < n; ++ i ) {
            if(i % 2 == 0) utod.push_back(generateUpLine(i / 2, utod[utod.size() - 1], dtou[dtou.size() - 1], n));
            else dtou.push_back(generateDownLine(i / 2, dtou[dtou.size() - 1], n));
        }
        
        for(int i = dtou.size() - 1; i >= 0; -- i)
            utod.push_back(dtou[i]);
            
        return utod;
    }
    
    vector<int> generateUpLine(int k, vector<int>& up, vector<int>& down, int n) {
        vector<int> v;
        v.clear();
        for(int i = 0; i < k; ++ i)
            v.push_back(n - 2 * k + down[i]);
        for(int i = k; i < n - k; ++ i)
            v.push_back(v[i - 1] + 1);
        for(int i = n - k; i < n; ++ i)
            v.push_back(up[i] + 1);
        
        return v;
    }
    
    vector<int> generateDownLine(int k, vector<int>& down, int n) {
        vector<int> v;
        v.clear();
        for(int i = 0; i < k; ++ i)
            v.push_back(down[i] + 1);
        v.push_back(down[k - 1] + 4 * n - 8 * k - 2);
        for(int i = k + 1; i < n - k; ++ i)
            v.push_back(v[i - 1] - 1);
        for(int i = n - k; i < n; ++ i)
            v.push_back(down[i] - 1);
        
        return v;
    }
};
