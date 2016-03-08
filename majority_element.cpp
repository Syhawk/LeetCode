//uri:	https://leetcode.com/problems/majority-element/

/*
 *	根据主要元素数量会在一半以上这一个条件，两个变量分别存储当前元素值以及该元素的个数，遇到不同元素，元
 *	素个数减一，否则加一。元素个数变为负数时，则换为其他元素，最后一个保留下的元素就是要查找的元素。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i = nums.size() - 1, cnt = 1; i > 0; -- i) {
            if(nums[i] == nums[0]) ++ cnt;
            else cnt --;
            
            if(cnt < 0) {
                nums[0] = nums[i];
                cnt = 1;
            }
        }
        
        return nums[0];
    }
};
