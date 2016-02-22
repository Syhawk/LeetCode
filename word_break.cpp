//uri:	https://leetcode.com/problems/word-break/

/*
 *	采用宽度优先遍历的方式：首先找出字典中字符串的最大长度和最小长度，这是从母串中
 *	选取连续字符的区间限额。通过访问标记的方式进行剪枝。若曾经访问过某一节点，那么
 *	，队列中就不应再加入该节点。
 *	空间复杂度：O(n^2).
 *	时间复杂度：O(n^2).
 * */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int MAX = 0, MIN = 0x7fffffff;
        int size = s.size();
        vector<bool> vis(size, 0);
        unordered_set<string>::iterator itr = wordDict.begin();
        for( ; itr != wordDict.end(); ++ itr) {
            MAX = max((int)(*itr).size(), MAX);
            MIN = min((int)(*itr).size(), MIN);
        }
        
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int p = q.front();
            q.pop();
            
            if(p >= size) return true;
            
            for(int i = MIN; i + p <= size && i <= MAX; ++ i) {
                if(vis[p + i - 1]) continue;
                if(wordDict.find(s.substr(p, i)) == wordDict.end()) continue;
                
                vis[p + i - 1] = true;
                q.push(p + i);
            }
        }
        
        return false;
    }
};
