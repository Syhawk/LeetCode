//uri:	https://leetcode.com/problems/find-the-duplicate-number/

/*
 *	由于只能使用常量空间，而且不能修改原来的数组，且数据集为1-n，重复的数字
 *	只有一个，所以采用二分查找的方式。一个区间内的元素值统计个数，如果满足
 *	恰好等于区间长度，那么这个区间就不存在重复的元素，否则就存在。
 *	空间复杂度：O(1).
 *	时间复杂度：O(nlogn).
 * */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        int len = right + 1;
        int back = 1;
        int mid = 1;

        while(left <= right) {
        	mid = ((right - left) >> 1) + left;
        	int cnt = 0;

        	for(int i = 0; i < len; ++ i)
        		if(nums[i] <= mid && nums[i] >= left) ++ cnt;

        	//cout << left << " " << mid << " " << right << " " << cnt << endl;

        	if(cnt <= mid - left + 1)
        		left = mid + 1;
        	else
        		right = mid;

        	back = mid;
        	if(left == right && left == mid)
        		break;

        }
        return back;
    }
};
