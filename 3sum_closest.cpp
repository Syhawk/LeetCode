//uri:	https://leetcode.com/problems/3sum-closest/

/*
 *	找出三个数，使得三个数之和为target，找出所有这样的组合总数并返回。
 *	首先，对所有的数非递减排序。然后，我们可以采用两层循环遍历来解决问题。
 *	第一层循环从0开始，步数为1.第二层循环有两个下标，
 *	一个是从第一层开始的下标+1的位置开始，另一个是从数据集最后一个数字下标开始。
 *	一个递增，一个递减，每次步数为1。三个数之和与target相减，判断结果。
 *	结果为0，就找到了这样的一组数，不为0就判断大于0还是小于0；大于0，
 *	第二层下标递减；小于0第二层下标递增。等于0，第二层下标递增递减均可。
 *	第一层循环：当前的数与上一个数相同，就不要进入第二层循环。
 *	第二层循环：递增下标小于递减下标。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n^2).
 * */


inline bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), cmp);
        int size = nums.size();
        int r = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < size - 2 && r - target != 0; ++ i) {
            if(i && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1, k = size - 1; j < k && r - target != 0; ) {
                int t = nums[i] + nums[j] + nums[k];
                if(abs(t - target) < abs(r - target))
                    r = t;
                if(t <= target) ++ j;
                else -- k;
            }
        }
        
        return r;
    }
};
