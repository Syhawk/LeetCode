//uri:	https://leetcode.com/problems/unique-binary-search-trees/

/*
 *	卡特兰数
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;
        long long int x = 2;
        for(int i = 3; i <= n; ++ i)
            x = x * (4 * i - 2) / (i + 1);
        return x;
    }
};
