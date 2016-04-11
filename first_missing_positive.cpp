//uri:	https://leetcode.com/problems/first-missing-positive/

/*
 *	由于要查找出[1, len]之间最先缺少哪一个正整数，那么，我们可以按照某种规则把所有的元素值在区间[1, len]的放回到应该呆在的位置。
 *	即，如果一个元素值val在区间[1, len]之间，且这个值应该放在下标val - 1处，如果下标val - 1处已经存在这个值，就不需要交换元素值，
 *	否则就交换当前元素值与下标val - 1的元素值。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++ i) {
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < len; ++ i) {
            if(nums[i] != i + 1) { return i + 1; }
        }
        
        return len + 1;
    }
};
