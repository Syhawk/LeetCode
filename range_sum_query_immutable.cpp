//uri:	https://leetcode.com/problems/range-sum-query-immutable/

/*
 *	每次得出区间[i, j]内的元素值之和，那么可以进行预处理，一次性求出区间[0, i]
 *	内的元素值之和，区间[i, j]内的元素值之和就等于：[0, j] - [0, i - 1]
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class NumArray {
public:
    NumArray(vector<int> &nums) {
        p = &nums;
        int len = nums.size();
        for(int i = 1; i < len; ++ i)
            nums[i] += nums[i - 1];
    }

    int sumRange(int i, int j) {
        if(i)
            return (*p)[j] - (*p)[i - 1];
        return (*p)[j];
    }

private:
    vector<int> *p;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
