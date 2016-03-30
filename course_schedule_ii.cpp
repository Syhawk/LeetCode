//uri:	https://leetcode.com/problems/course-schedule-ii/

/*
 *	采用topological sort的方式，改为宽度优先遍历查找环。为了存储数据方便，把整个
 *	有向图逆转一下，即：由(u, v)改为(v, u)。
 *	空间复杂度：O(max(n, m)).
 *	时间复杂度：O(max(n, m)).
 * */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> g[numCourses];
        vector<int> indegree(numCourses, 0);
        
        for(int i = prerequisites.size() - 1; i >= 0; -- i) {
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            ++ indegree[prerequisites[i].first];
        }
        
        vector<int> v;
        queue<int> q;
        for(int i = 0; i < numCourses; ++ i) {
            if(indegree[i] == 0) { q.push(i); }
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            v.push_back(u);
            
            for(int i = g[u].size() - 1; i >= 0; -- i) {
                -- indegree[g[u][i]];
                if(indegree[g[u][i]] == 0) { q.push(g[u][i]); }
            }
        }
        
        if(v.size() != numCourses) { v.clear(); }
        
        return v;
    }
};
