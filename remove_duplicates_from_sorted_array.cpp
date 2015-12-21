//uri:	https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/*
 *	移除重复元素值，并返回移除重复元素值之后的长度。nums有序，且只有一个元素值
 *	重复，那么可以从nums头部遍历至尾部，如果不是重复元素，就进行移动；否则不移动。
 *	i + 1表示不存在重复元素的数组长度。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 1)
            return 0;
        int i = 0;
        for(int j = 1; j < len; ++ j) {
            if(nums[i] != nums[j])
                nums[++ i] = nums[j];
        }
        
        return i + 1;
    }
};
