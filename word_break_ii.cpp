//uri:	https://leetcode.com/problems/word-break-ii/

/*
 *	从文本字符串s的尾部向头部开始查找，如果在某个的下标u开始查找到了某个单词，就把该单词在s中的前一个下标index - 1加入队列，
 *	而且只能加入一次，如果已经加入过该下标，就不再加入。并且把index -> u加入图，最终实现构图。
 *	对已构建的图进行遍历，找出所有从0节点到最后一个节点的所有路径。
 *	空间复杂度：O().
 *	时间复杂度：O().
 * */

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        vector<bool> vis(s.size() + 1, 0);
        vector<int> lens;
        queue<int> q;
        vector<int> G[s.size()];
        
        for ( auto itr = wordDict.begin(); itr != wordDict.end(); ++ itr ) {
            if ( itr -> size() <= s.size() ) { vis[itr -> size()] = true; }
        }
        
        for ( int i = 0; i <= s.size(); ++ i ) {
            if ( vis[i] ) {
                lens.push_back(i);
                vis[i] = false;
            }
        }
        
        q.push(s.size() - 1);
        
        while ( !q.empty() ) {
            auto p = q.front();
            q.pop();
            
            for ( int i = 0; i < lens.size() && p - lens[i] + 1 >= 0; ++ i ) {
                int index = p - lens[i] + 1;
                if ( wordDict.find(s.substr(index, lens[i])) == wordDict.end() ) { continue; }
                if ( !vis[index] ) { q.push(index - 1); }
                
                vis[index] = true;
                G[index].push_back(p);
            }
        }
        
        string _r;
        DFS(0, G, s, _r, result);
        
        return result;
    }
    
    void DFS(int index, vector<int>* G, string& s, string& _r, vector<string>& result) {
        if ( index >= s.size() ) {
            result.push_back(_r);
            return;
        }
        
        for ( int i = 0; i < G[index].size(); ++ i ) {
            int u = G[index][i];
            if ( _r.size() ) { _r += " "; }
            _r += s.substr(index, u - index + 1);
            DFS(u + 1, G, s, _r, result);
            _r.erase(_r.size() - (u - index + 1), u - index + 1);
            if ( _r.size() ) { _r.erase(_r.size() - 1, 1); }
        }
    }
};
