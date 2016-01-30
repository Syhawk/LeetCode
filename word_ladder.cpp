//uri:	https://leetcode.com/problems/word-ladder/

/*
 *	采用bfs进行暴力解决。
 *	空间复杂度：O(wordList).
 *	时间复杂度：O(wordList)
 * */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> strs;
        
        wordList.insert(endWord);
        q.push(make_pair(beginWord, 1));
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            string s = p.first;
            if(s == endWord) return p.second;
            
            for(int i = s.size() - 1; i >= 0; -- i) {
                char ch = s[i];
                
                for(int j = 0; j < 26; ++ j) {
                    s[i] = char('a' + j);
                    if(wordList.find(s) != wordList.end() && strs.find(s) == strs.end()) {
                        strs.insert(s);
                        q.push(make_pair(s, p.second + 1));
                    }
                }
                s[i] = ch;
            }
        }
        
        return 0;
    }
};
