//uri:	https://leetcode.com/problems/3sum/

/*
 *	找出三个数，使得三个数之和为0，找出所有这样的集合并返回。
 *	由于给出的数是非递减的，那么，我们可以采用两层循环遍历来解决问题。
 *	第一层循环从0开始，步数为1.第二层循环有两个下标，
 *	一个是从第一层开始的下标+1的位置开始，另一个是从数据集最后一个数字下标开始。
 *	一个递增，一个递减，每次步数为1。三个数之和为0就把三个数存储起来，
 *	不为0就判断大于0还是小于0；大于0，第二层下标递减；小于0第二层下标递增。
 *	等于0，第二层下标递增递减均可。
 *	由于不能存储重复的集合，所以需要在循环的某些地方作一些约束：
 *	第一层循环：当前的数与上一个数相同，就不要进入第二层循环。
 *	第二层循环：递增下标小于递减下标。如果得出的三个数与上次得出的三个数相同
 *	就不需要存储。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n^2).
 * */

bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        int size = nums.size();
        vector<vector<int>> r;
        r.clear();
        
        int x = -1, y = -1, z = -1;
        for(int i = 0; i < size - 2 && nums[i] <= 0; ++ i) {
            if(i && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1, k = size - 1; j < k; ) {
                int t = nums[i] + nums[j] + nums[k];
                if(t == 0 && (x != nums[i] || y != nums[j] || z != nums[k])) {
                    r.push_back({nums[i], nums[j], nums[k]});
                    x = nums[i];
                    y = nums[j];
                    z = nums[k];
                }
                
                if(t <= 0)
                    ++ j;
                else 
                    -- k;
            }
        }
        
        return r;
    }
};
