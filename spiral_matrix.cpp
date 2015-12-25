//uri:	https://leetcode.com/problems/spiral-matrix/

/*
 *	从外层以顺时针方向访问二维数组，每次外层访问可以分为四个单循环组成：
 *	最上面一行、最右侧一列、最下面一行和最左侧一列。
 *	空间复杂度：O(m*n).
 *	时间复杂度：O(m*n).
 * */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        
        if(matrix.size() < 1) return v;
        
        int up = 0, left = 0, down = matrix.size() - 1, right = matrix[0].size() - 1;
        while(left <= right && up <= down) {
            // 最上面一行
            for(int i = left; i <= right; ++ i)
                v.push_back(matrix[up][i]);
            
            //  最右侧一列
            for(int i = up + 1; i <= down; ++ i)
                v.push_back(matrix[i][right]);
        
            //  最下面一行
            if(up != down) for(int i = right - 1; i >= left; -- i)
                v.push_back(matrix[down][i]);
            
            //  最左侧一列
            if(left != right) for(int i = down - 1; i > up; -- i)
                v.push_back(matrix[i][left]);
            
            left += 1;
            right -= 1;
            up += 1;
            down -= 1;
        }
        
        return v;
    }
};
