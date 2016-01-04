//uri:	https://leetcode.com/problems/set-matrix-zeroes/

/*
 *	题目要求额外辅助空间只能是常量，那么就利用矩阵存储相应信息。
 *	设置两个bool变量，分别表示第一行或者第一列是否需要转换为0。
 *	第一行转换为0的条件是：matrix[0][j] == 0.
 *	第一列转换为0的条件是：matrix[i][0] == 0.
 *	然后二层循环遍历矩阵，遇到matrix[i][j] == 0，那么这一行和这一列就要赋值为0.
 *	信息标记只需要在这一行和这一列的开始位置赋值为0.
 *	然后循环第一行和第一列，第一行每存在一个元素的值为0，就表示该元素所在的这一列
 *	要赋值为0；第一列每存在一个元素的值为0，就表示该元素所在的这一行要赋值为0.
 *	最后根据两个bool变量的值判断第一行和第一列是否要赋值为0.
 *	空间复杂度：O(1).
 *	时间复杂度：O(m*n).
 * */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool flg_col = false, flg_row = false;
        
        for(int i = 0; i < row; ++ i) {
            for(int j = 0; j < col; ++ j) {
                if(matrix[i][j] != 0) continue;
                
                matrix[0][j] = 0;
                matrix[i][0] = 0;
                
                if(i == 0) flg_col = true;
                if(j == 0) flg_row = true;
            }
        }
        
        for(int i = 1; i < row; ++ i) {
            if(matrix[i][0] != 0) continue;
            for(int j = 1; j < col; ++ j)
                matrix[i][j] = 0;
        }
        
        for(int j = 1; j < col; ++ j) {
            if(matrix[0][j] != 0) continue;
            for(int i = 1; i < row; ++ i)
                matrix[i][j] = 0;
        }
        
        if(flg_row) for(int i = 0; i < row; ++ i) matrix[i][0] = 0;
        if(flg_col) for(int j = 0; j < col; ++ j) matrix[0][j] = 0;
    }
};
