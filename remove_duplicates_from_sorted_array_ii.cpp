//uri:	https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

/*
 *	每一个元素的出现次数最多为两次，多于两次则数组内删除多于的次数，剩下两次。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size < 1) return 0;
        
        int cnt = 1;
        int k = 1;
        for(int i = 1; i < size; ++ i) {
            if(nums[i] != nums[k - 1]) {
                nums[k ++] = nums[i];
                cnt = 1;
                continue;
            }
            if(cnt >= 2) continue;
            nums[k ++] = nums[i];
            ++ cnt;
        }
        
        return k;
    }
};
