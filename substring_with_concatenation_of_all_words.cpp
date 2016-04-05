//uri:	https://leetcode.com/problems/substring-with-concatenation-of-all-words/

/*
 *	方法暂时有两种，一种是借助于容器map，由于每个word长度相同，而且word存在重复，所以可以用map直接暴力。
 *	另一种是在word与s匹配的时候，可以不暴力匹配，而是采用字符串匹配算法进行优化：例如kmp算法，Sunday算法，
 *	BM算法等等，大大减少时耗。
 *	时间复杂度：O(m * n).
 *	空间复杂度：O(max(m, n)).
 * */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = s.size();
        int w_sum = words.size();
        int len = words[0].size();
        if(len <= 0 || w_sum <= 0 || len <= 0 || s_len < w_sum * len) { return vector<int>(); }

        unordered_map<string, int> _map;
        for(int i = 0; i < w_sum; ++ i) { _map[words[i]] += 1; }
        
        vector<int> result;
        int _len = s_len - w_sum * len + 1;
        for(int i = 0, cnt = 0; i < _len; ++ i, cnt = 0) {
            unordered_map<string, int> __map;
            for(int j = i; j < s_len; j += len) {
                string _s = s.substr(j, len);
                if(_map.find(_s) == _map.end()) { break; }
                __map[_s] += 1;
                if(__map[_s] > _map[_s]) { break; }
                ++ cnt;
            }
            
            if(cnt == w_sum) { result.push_back(i); }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = s.size();
        int w_sum = words.size();
        int len = words[0].size();
        if(w_sum <= 0 || len <= 0 || s_len < w_sum * len) { return vector<int>(); }

        vector<int> G(s_len, -1);
        sort(words.begin(), words.end());
        vector<int> kinds(w_sum, 0);
        int t = 0;
        for(int i = 0; i < w_sum; ++ i) {
            if(words[i] != words[t]) {
            	kinds[++ t] = 1;
            	words[t] = words[i];
            }
            else { ++ kinds[t]; }
        }
        t += 1;
        swap(t, w_sum);
        
        for(int i = 0; i < w_sum; ++ i) {
            vector<int> getNext(26, len);
            bool flg = false;
            for(int j = 0; j < len; ++ j) { getNext[words[i][j] -'a'] = len - j; }
          
            for(int j = 0; j < s_len - len + 1; ) {
                for(int k = 0; k < len && j + k < s_len; ++ k) {
                    if(words[i][k] != s[j + k]) {
                    	if(j + len >= s_len) { j = s_len; }
                        else { j += getNext[s[j + len] -'a']; }
                        break;
                    }
                    if(k == len - 1) {
                        G[j] = i;
                        ++ j;
                        flg = true;
                    }
                }
            }
            
            if(flg == false) { return vector<int>(); }
        }

        vector<int> result;
        int _len = s_len - t * len + 1;
        for(int i = 0, cnt = 0; i < _len; ++ i, cnt = 0) {
            vector<int> vis(w_sum, 0);
            for(int j = i; j < s_len && G[j] != -1 && vis[G[j]] < kinds[G[j]]; j += len) {
                cnt += 1;
                vis[G[j]] += 1;
            }
            if(cnt == t) { result.push_back(i); }
        }
        
        return result;
    }
};
