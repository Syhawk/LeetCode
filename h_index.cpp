//uri:	https://leetcode.com/problems/h-index/

/*
 *	对一个无序数组，查找一个数满足比该数大的数的个数不比该数大，找出比该数大的最大
 *	个数。先排序，然后遍历，第一个满足的数就是了。
 *	空间复杂度：O(1).
 *	时间复杂度：O(nlogn).
 * */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0) return len;
        
        int maxium = 0;
        sort(citations.begin(), citations.end());

        for(int i = 0; i < len; ++ i) {
            if(citations[i] == 0) continue;
            if(citations[i] >= len - i)
                return len - i;
        }
        
        return maxium;
    }
};
