//uri:	https://leetcode.com/problems/unique-paths/

/*
 *	用数组进行模拟，将原本采用的二维数组模拟转化为一维数组进行模拟。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n*m).
 * */

class Solution {
public:
    int uniquePaths(int m, int n) {
        for(int i = 1; i <= n; ++ i) 
            grid[i] = 0;
        grid[1] = 1;
             
        for(int i = 1; i <= m; ++ i)
            for(int j = 2; j <= n; ++ j)
                grid[j] += grid[j - 1];
        
        return grid[n];
    }
    
private:
    int grid[110];
};
