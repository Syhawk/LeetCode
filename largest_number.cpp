//uri:	https://leetcode.com/problems/largest-number/

/*
 *	此题目的关键在于编写sort快排函数的比较函数，然后再注意一下输入元素全部为0的情况。比较函数里的元素
 *	转换成字符串形式，对两个字符串的组合形式进行排序，哪一个在排头的位置比较大，就是哪一个元素比较大。
 *	空间复杂度：O(m * n).
 *	时间复杂度：O(m * n).
 * */

static bool cmp(const string& p, const string& q) {
    return (p + q) > (q + p);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        int len = nums.size();
        for(int i = len - 1; i >= 0; -- i)
            v.push_back(to_string(nums[i]));
            
        sort(v.begin(), v.end(), cmp);
        
        if(v[0][0] == '0') return "0";
        
        for(int i = 1; i < len; ++ i)
            v[0] += v[i];
            
        return v[0];
    }
};
