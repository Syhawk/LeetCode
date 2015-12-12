//uri:	https://leetcode.com/problems/next-permutation/

/*
 *	查找下一个排列，那么就相当于从数组尾部往前开始寻找到某个点，对这一段元素
 *	进行排列，找出比此段元素构成的排列要大的排列。
 *	算法：从数组尾部循环遍历至数组头部，步数为一，元素值出现下降点终止。
 *	从数组尾部开始寻找比此下降点大的第一个元素，然后交换。
 *	从尾部到下降点之前的元素翻转。
 * */

class Solution {
public:
	void nextPermutation(vector<int>& nums){
		int size = nums.size();
		if(size == 1) return;
		int i = size - 2;
		for( ; i >= 0 && nums[i] >= nums[i + 1]; -- i) ;

		if(i >= 0) {
			int j = size - 1;
			for( ; j > i && nums[j] <= nums[i]; -- j) ;
			swap(nums[i], nums[j]);
		}

        i += 1;
		for(int j = size - 1; i < j; ++ i, -- j) {
			swap(nums[i], nums[j]);
		}
	}
};


/*
 *	使用C++ STL里面的next_permutation函数
 *	（对应的也有prev_permutation函数）
 * */

class Solution {
public:
	void nextPermutation(vector<int>& nums){
		next_permutation(nums);
	}
};
