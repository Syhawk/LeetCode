//uri:	https://leetcode.com/problems/combination-sum-ii/

/*
 *	从给定数据中找出一组数据集，这组数据集的数据之和为target，数据集内可以存在
 *	重复元素，但是不能存在相同数据集，数据集内元素非递减排序，
 *	找出所有数据集并返回。
 *	采用宽度优先遍历的方式，构建struct类型，分别代表当前数据集元素，元素之和，
 *	下一次选取元素的下标。满足条件就存储起来，不满足条件就判断是不是要加入队列。
 *	由于不能存在相同数据集，所以在筛选元素的时候，判断重复元素。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n^2).
 * */

struct Node {
    vector<int> sv;
    int index;
    int sum;
    Node(vector<int> x, int y, int z) : sv(x), index(y), sum(z) {}
};

inline bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), cmp);
        
        int len = candidates.size();
        vector<vector<int>> v;
        if(len < 1) return v;
        if(candidates[0] > target) return v;
        
        queue<Node> q;
        q.push(Node({0}, 0, 0));
        while(!q.empty()) {
            Node p = q.front();
            q.pop();
            int index = p.index;
            for(int i = index; i < len; ++ i) {
                if(i != index && candidates[i] == candidates[i - 1])
                    continue;
                    
                p.index = i + 1;
                p.sum += candidates[i];
                p.sv.push_back(candidates[i]);
                
                if(p.sum > target) break;
                if(p.sum == target) {
                    vector<int> t(p.sv.begin() + 1, p.sv.end());
                    v.push_back(t);
                    break;
                }
                q.push(p);
                
                p.sum -= candidates[i];
                p.sv.pop_back();
            }
        }
        
        return v;
    }
};
