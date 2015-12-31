//uri:	https://leetcode.com/problems/move-zeroes/

/*
 *	用两个下标分别表示当前出现第一个0数字的下标和当前0下标之后第一个出现的非零数字
 *	的下标，两个下标的值进行交换，然后循环至结束。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int zero = 0, other = 0;

        while(zero < len && other < len) {
            while(zero < len && nums[zero] != 0) ++ zero;
            other = max(zero + 1, other);
            while(other < len && nums[other] == 0) ++ other;

            if(other < len) {
                nums[zero] = nums[other];
                nums[other] = 0;
            }

            ++ zero;
        }
    }
};
