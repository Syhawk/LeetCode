//uri:	https://leetcode.com/problems/remove-element/

/*
 *	从一个无序数组中移除所有与val值相同的元素可以借用快排里面的函数。
 *	定义两个下标变量i, j且i < j + 1。i从头部递增，j从尾部递减。i遇到
 *	与val值相等的元素就停止，j遇到与val值不等的元素就停止。然后交换
 *	两个元素值。一直这样循环下去，直至没有可以交换的元素为止，返回i。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0, j = len - 1;
        //if(j == 0)
         //   return (nums[0] != val);
        while(i < j + 1) {
            while(i < j + 1 && nums[i] != val) ++ i;
            while(j > i && nums[j] == val) -- j;
            if(j > i) swap(nums[i], nums[j]);
            if(i == j) break;
        }
        
        return i;
    }
};
