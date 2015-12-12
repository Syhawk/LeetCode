/*
 *	首先对数组nums的下标index升序排序，排序准则是根据当前下标
 *	在nums所表示元素的大小。
 *	然后取两个下标变量，分别从index头部和尾部进行遍历，根据下标所代表
 *	元素在nums作为下标获取相应元素值，对数值之和进行判断。
 *	得到最终目标后，index下标所表示的元素就是两个数字在nums分别所代表的下标。
 * */
vector<int>* v;

bool cmp(const int i, const int j) {
	return (*v)[j] > (*v)[i];
}

class Solution {
public:		    
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index = {};
		int len = nums.size();
		v = &nums;
		for(int i = 0; i < len; ++ i)
		index.push_back(i);
												        
		sort(index.begin(), index.end(), cmp);
		vector<int> r = {};
		for(int i = 0, j = len - 1; i < len - 1; ++ i) {
			int lhs = index[i];
			int rhs = index[j];
			while(nums[lhs] + nums[rhs] > target) {
				--j;
				rhs = index[j];
			}
			
			if(nums[lhs] + nums[rhs] == target) {
				r.push_back(min(lhs, rhs) + 1);
				r.push_back(max(rhs, lhs) + 1);
				break;
			}
		}

		return r;
	}
};
