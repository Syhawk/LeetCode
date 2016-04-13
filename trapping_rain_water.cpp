//uri:	https://leetcode.com/problems/trapping-rain-water/

/*
 *	计算存水量，我们可以从两边同时计算。其中每一区域[i, j]的存水量就是：(j - i - 1) * min(height[i], height[j]) - sum;
 *	sum为区间(i, j)的height[k]的总和。于是，我们可以设定height[j] >= height[i],那么从前往后遍历，只需要找到height[j] >=
 *	height[i]的区间进行计算；由于我们是从两边同时计算,同理，从尾到前，[k, l]，我们使得height[k] >= height[l]，按照上述
 *	计算存水量的公式计算。最终把这些区间加起来并返回。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int trap(vector<int>& height) {
        int cnt = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            int k = i + 1;
            int sum = 0;
            for ( ; k <= j && height[i] > height[k]; ++ k) { sum += height[k]; }
            if (k <= j) {
                cnt += height[i] * (k - i - 1) - sum;
                i = k;
            }
            
            k = j - 1;
            for (sum = 0; k >= i && height[j] > height[k]; -- k) { sum += height[k]; }
            if (k >= i) {
                cnt += height[j] * (j - k - 1) - sum;
                j = k;
            }
        }
        
        return cnt;
    }
};
