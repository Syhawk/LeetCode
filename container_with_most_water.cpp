//uri:	https://leetcode.com/problems/container-with-most-water/

/*
 *	寻找两块木板，加上X轴所围成的区域蓄水量最大为多少。蓄水量取决于最小木板，
 *	那么就从数组两端往中心区域遍历，直至选出这一最大区域。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int x = 0;
        for(int i = 0, j = height.size() - 1; i < j; ) {
            x = max(x, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j])
                -- j;
            else ++ i;
        }
        
        return x;
    }
};
