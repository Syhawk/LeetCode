//uri:	https://leetcode.com/problems/clone-graph/

/*
 *	将一个图克隆一下，然后返回这个克隆图。由于label有负数，并不是完全以0为头节点
 *	进行递增来表示一张图，所以，需要转换。当然也可借助于unordered_map之类的容器，
 *	判断节点是否访问过，以及存储该节点的指针。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> sets;
        unordered_map<int, bool> vis;
        
        return dfs(node, sets, vis);
    }
    
    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<int, UndirectedGraphNode*>& sets, unordered_map<int, bool>& vis) {
        if(node == nullptr) return nullptr;
        if(vis.find(node -> label) != vis.end()) return nullptr;
        
        vis[node -> label] = true;
        if(sets.find(node -> label) == sets.end())  sets[node -> label] = new UndirectedGraphNode(node -> label);
        UndirectedGraphNode* head = sets[node -> label];
        
        int len = node -> neighbors.size();
        for(int i = 0; i < len; ++ i) {
            auto ptr = node -> neighbors[i];
            if(sets.find(ptr -> label) == sets.end()) sets[ptr -> label] = new UndirectedGraphNode(ptr -> label);
            
            head -> neighbors.push_back(sets[ptr -> label]);
            
            dfs(ptr, sets, vis);
        }
        
        return head;
    }
};
