//uri:	https://leetcode.com/problems/anagrams/

/*
 *	先对字符串向量排序，排序方式类似于先对每个字符串内的字符排序，然后再对字符串
 *	排序，只不过下面代码采用一个整数数组对字符串内字符进行统计，并没有对该字符串
 *	内字符排序。而这个只能适用于同等长度的字符串，所以，如果长度不想同，就按照长
 *	度排序，否则统计字符个数排序。排完序之后就可以统计归类了。
 *	空间复杂度：O(n * m).
 *	时间复杂度：O(n * m * log(n * m)).
 * */

int cnt[26];

inline bool cmp(const string& p, const string& q) {
    if(p.size() != q.size())
        return p.size() < q.size();
        
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; p[i]; ++ i)
        ++ cnt[p[i] - 'a'];
    for(int i = 0; q[i]; ++ i)
        -- cnt[q[i] - 'a'];
    for(int i = 0; i < 26; ++ i) {
        if(cnt[i] > 0) return 1;
        else if(cnt[i] < 0) return 0;
    }
    
    return 0;
}

inline bool comp(const string& p, const string& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        
        vector<vector<string>> v;
        int len = strs.size();
        if(len < 1) return v;
        vector<string> tmp;
        tmp.push_back(strs[0]);
        
        for(int i = 1; i < len; ++ i) {
            int j;
            memset(cnt, 0, sizeof cnt);
            for( j = 0; strs[i][j]; ++ j)
                ++ cnt[strs[i][j] - 'a'];
            for( j = 0; tmp[0][j]; ++ j)
                -- cnt[tmp[0][j] - 'a'];
                
            for( j = 0; j < 26 && cnt[j] == 0; ++ j) ;
                
            if(j < 26) {
                sort(tmp.begin(), tmp.end(), comp);
                v.push_back(tmp);
                tmp.clear();
                tmp.push_back(strs[i]);
            } else {
                tmp.push_back(strs[i]);
            }
        }
        
        sort(tmp.begin(), tmp.end(), comp);
        v.push_back(tmp);
              
        return v;
    }
};
