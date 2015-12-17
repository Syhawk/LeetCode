//uri:	https://leetcode.com/problems/combination-sum/

/*
 *	寻找数据集满足数据集所包含元素之和为特定值。数据集要求元素从小到大排列，
 *	且不能存在相同数据集，数据集里面的元素可以重复。
 *	因此，可以采用宽度优先遍历的方式。为了给宽度优先遍历剪纸，先给给出的数据
 *	升序排序。然后从第一个数值开始遍历，找出所有可能的数据集。
 *	空间复杂度：O(n^2).
 *	时间复杂度：O(n^2).
 * */

struct Node {
    vector<int> sv;
    int index;
    int sum;
    Node(vector<int> x, int y, int z) : sv(x), index(y), sum(z) {}
};

bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), cmp);
        vector<vector<int>> v;
        int len = candidates.size();
        if(len < 1) return v;
        if(candidates[0] > target) return v;
        
        queue<Node> q;
        vector<int> p;
        p.clear();
        p.push_back(0);
        q.push(Node(p, 0, 0));
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            for(int i = node.index; i < len; ++ i ) {
                node.sv.push_back(candidates[i]);
                node.sum += candidates[i];
                node.index = i;
                
                if(node.sum > target) break;
                if(node.sum == target) {
                    vector<int> t(node.sv.begin() + 1, node.sv.end());
                    v.push_back(t);
                    break;
                }
                
                q.push(node);
                node.sv.pop_back();
                node.sum -= candidates[i];
            }
        }
        
        return v;
    }
};
