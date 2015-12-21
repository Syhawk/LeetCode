//uri:	https://leetcode.com/problems/permutations-ii/

/*
 *	求出所有唯一的排列。那么，为了保证每次得出的排列都是唯一的，
 *	可以调用next_permutation函数，这个函数就是在原来排列的基础上求得下一个排列。
 *	其原理实现是根据排列的特性：排列每次都是从尾后变化开始的，从尾后开始一定存在
 *	某个非递减子序列，然后到某个位置终止（否则就是最大排列，就不再需要寻找下一
 *	个排列），从这个终止位置开始到尾后这一段就需要重新排列，其他位置则不会变化。
 *	就是相当于从尾后开始寻找第一个出现的大于终止位置元素值的元素，然后交换位置。
 *	最后再把终止位置上一个位置到尾后变为非递减序列即可。
 *	空间复杂度：O(n!).
 *	时间复杂度：O(n! * n).
 * */

inline bool cmp(const int& p, const int& q) {
    return p < q;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> pers;
        sort(nums.begin(), nums.end(), cmp);
        pers.push_back(nums);
        size = nums.size();
        
        if(size <= 1) return pers;
        
        while(next_permutation(nums)) {
            pers.push_back(nums);
        }
        
        return pers;
    }
    
    bool next_permutation(vector<int>& nums) {
        int i = size - 2;
        for( ; i >= 0 && nums[i] >= nums[i + 1]; -- i ) ;
        if(i == -1) return false;
        
        int j = size - 1;
        for( ; j > i && nums[j] <= nums[i]; -- j );
        swap(nums[i], nums[j]);
        
        for(int k = i + 1, l = size - 1; k < l; ++ k, -- l)
            swap(nums[k], nums[l]);
        
        return true;
    }

private:
    int size;
};
