//uri:	https://leetcode.com/problems/sort-colors/

/*
 *	将数组以非递减顺序排序。数组里面由于最多只出现三种数字：0、1、2，所以可以先
 *	排数字1，再排数字2，最后排数字3。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int flg = 0, i = 0, j = 0;
        while(i < size) {
            if(nums[i] == flg) {
                ++ i;
                continue;
            }
            
            j = max(i + 1, j);
            while(j < size && nums[j] != flg) {
                ++ j;
            }
            
            if(j < size) {
                swap(nums[i], nums[j]);
            } else {
                flg += 1;
                j = i;
            }
        }
    }
};
