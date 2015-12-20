//uri:	https://leetcode.com/problems/permutations/

/*
 *	全排列采用深度优先遍历或者宽度优先遍历均可。
 *	深度优先遍历（dfs）：用一个vis布尔数组进行标记，访问过的元素标记为1，
 *	否则标记为0。访问过的元素全都加入到一个临时vector<int>中，等到所有元素
 *	都访问一次后，就把该临时vector<int>放入最终要返回的vector<vector<int>>中。
 *	空间复杂度：O(n!).
 *	时间复杂度：O(n^n).
 * */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        per.clear();
        memset(vis , 0, sizeof vis);
        
        dfs(nums);
        
        return v;
    }
    
    void dfs(vector<int>& nums) {
        int size = nums.size();
        
        if(size == per.size()) {
            v.push_back(per);
            return;
        }
        
        for(int i = 0; i < size; ++ i) {
            if(vis[i]) continue;
            
            vis[i] = true;
            per.push_back(nums[i]);
            dfs(nums);
            
            per.pop_back();
            vis[i] = false;
        }
    }
    
private:
    vector<vector<int>> v;
    bool vis[20];
    vector<int> per;
};
