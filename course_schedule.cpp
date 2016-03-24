//uri:	https://leetcode.com/problems/course-schedule/

/*
 *	判断图中是否存在环，如果存在环，那么就返回false，否则就返回true。方式主要有两
 *	种，第一种，dfs，但是耗时比较多，第二种bfs。但是两种方式的空间复杂度与时间
 *	复杂度相同，耗时不同的原因是因为递归系统对栈的操作比较频繁，所以耗时多。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> vis(numCourses);
        vector<int> g[numCourses];
        
        auto p = &prerequisites;
        for(int i = p -> size() - 1; i >= 0; -- i) { g[(*p)[i].first].push_back((*p)[i].second); }
        
        for(int i = 0; i < numCourses; ++ i) {
            if(vis[i]) { continue; }
            if(!circle_dfs(vis, g, i)) { return false; }
        }
        
        return true;
    }
    
    bool circle_dfs(vector<bool>& vis, vector<int>* g, int u) {
        if(vis[u]) return false;
        vis[u] = true;
        
        for(int i = g[u].size() - 1; i >= 0; -- i) {
            if(!circle_dfs(vis, g, g[u][i])) { return false; }
        }
        
        vis[u] = false;
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> g[numCourses];
        
        auto p = &prerequisites;
        for(int i = p -> size() - 1; i >= 0; -- i) {
            ++ indegree[(*p)[i].second];
            g[(*p)[i].first].push_back((*p)[i].second);
        }
        
        return Topological(indegree, g, numCourses);
    }
    
    bool Topological(vector<int>& indegree, vector<int>* g, int n) {
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; ++ i) {
            if(indegree[i] == 0) { q.push(i); }
        }
        
        while(!q.empty()) {
            cnt += 1;
            int u = q.front();
            q.pop();
            
            for(int i = g[u].size() - 1; i >= 0; -- i) {
                -- indegree[g[u][i]];
                
                if(indegree[g[u][i]] == 0) { q.push(g[u][i]); }
            }
        }
        
        return cnt == n;
    }
};
