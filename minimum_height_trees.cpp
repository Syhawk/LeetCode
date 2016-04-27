//uri:	https://leetcode.com/problems/minimum-height-trees/

/*
 *	采用拓扑排序的方式，把入度等于0或者1的点加入队列，然后判断剩下的没有加入过入列的点是否 <= 2
 *	如果满足条件，把剩下的点返回，否则继续循环，向队列中加入点。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> G[n];
        vector<bool> vis(n, 0);
        vector<int> indegree(n, 0);
        for ( int i = edges.size() - 1; i >= 0; -- i )  {
            G[edges[i].first].push_back(edges[i].second);
            G[edges[i].second].push_back(edges[i].first);
            indegree[edges[i].second] += 1;
            indegree[edges[i].first] += 1;
        }
        
        vector<int> points;
        queue<int> qu;
        for ( int i = 0; i < n; ++ i ) {
            if ( indegree[i] <= 1 ) {
                points.push_back(i);
                vis[i] = true;
            }
        }
        
        int cnt = n;
        while ( cnt > 2 ) {
            for ( int i = points.size() - 1; i >= 0; -- i ) {
                qu.push(points[i]);
                points.pop_back();
            }
            
            while ( !qu.empty() ) {
                int u = qu.front();
                qu.pop();
                cnt -= 1;
                for ( int i = G[u].size() - 1; i >= 0; -- i ) {
                    indegree[G[u][i]] -= 1;
                    if ( indegree[G[u][i]] <= 1 && !vis[G[u][i]]) {
                        points.push_back(G[u][i]);
                        vis[G[u][i]] = true;
                    }
                }
            }
        }
        
        return points;
    }
};
