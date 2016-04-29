//uri:	https://leetcode.com/problems/maximum-product-of-word-lengths/

/*
 *	由于只有小写字母（26个小写字母），那么每个小写字母就分别表示一个整型32位中的一位。一个字符串，
 *	就可以用一个整数来表示其中不同的小写字母，两个整数相&的结果就是两个字符串中是否存在相同字母。
 *	通过对字符串长度进行排序，从而控制二维循环的次数可以进一步减少时耗。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n ^ 2)
 * */

inline bool cmp(const string& p, const string& q) { return p.size() > q.size(); }

class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<int> binary(words.size(), 0); 
        for ( int i = 0; i < words.size(); ++ i ) {
            for ( int j = 0; j < words[i].size(); ++ j ) {
                int sub = 1 << (words[i][j] - 'a');
                if ( (binary[i] & sub) == 0 ) { binary[i] ^= sub; }
            }
        }
        
        int _max = 0;
        for ( int i = 0; i < words.size(); ++ i ) {
            for ( int j = i + 1; j < words.size() && _max < words[i].size() * words[j].size(); ++ j ) {
                if ( (binary[i] & binary[j]) == 0 ) { _max = max(_max, int(words[i].size() * words[j].size())); }
            }
        }
        
        return _max;
    }
};
