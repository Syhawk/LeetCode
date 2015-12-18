//uri:	https://leetcode.com/problems/4sum/

/*
 *	从给定数据中找出4个数，使得这四个数之和为target。找出所有这样的组合，
 *	且不能重复，组合内的元素非递减排列。
 *	先对给定数据非递减排序，采用三层循环进行取值。第三层循环设置两个下标，
 *	一个递增下标，一个递减下标，递增下标小于递减下标。这样三层循环就有四个下标，
 *	分别代表四个元素，四个元素之和为target就存储，否则继续循环。
 *	由于不能选取重复组合，所以在每层循环判断当前下标元素是否与上一个元素重复。
 *	空间复杂度：O(n^2).(估计值)
 *	时间复杂度：O(n^3).
 * */

inline bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        sort(nums.begin(), nums.end(), cmp);

        int size = nums.size();
        for(int i = 0; i < size - 3; ++ i) {
            if(i && nums[i] == nums[i -1])
                continue;

            for(int j = i + 1; j < size - 2; ++ j) {
                if(j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                for(int k = j + 1, l = size - 1; k < l;) {
                    if(k != j + 1 && nums[k] == nums[k - 1]) {
                        ++ k;
                        continue;
                    }

                    int t = nums[i] + nums[j] + nums[k] + nums[l];
                    if(t == target) {
                        r.push_back({nums[i], nums[j],nums[k], nums[l]});
                    }

                    if(t <= target)
                        ++ k;
                    else -- l;
                }
            }
        }
        
        return r;
    }
};
