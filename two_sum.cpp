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
