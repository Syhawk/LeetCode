//uri:	https://leetcode.com/problems/range-sum-query-2d-immutable/

/*
 *	预先对matrix进行操作，使得matrix[i][j]表示matrix从左上角(0, 0)到右下角(i, j)所表示的矩形的数值和。
 *	然后每次对区域求和可以在O(1)时间内得出结果。
 *	空间复杂度：O(1).
 *	时间复杂度：O(m * n).
 * */

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        ptr = &matrix;
        int len_row = matrix.size();
        if ( len_row < 1 ) { return; }
        int len_col = matrix[0].size();
        for ( int i = 0; i < len_row; ++ i ) {
            for ( int j = 0; j < len_col; ++ j ) {
                if ( i && j ) { matrix[i][j] -= matrix[i - 1][j - 1]; }
                if ( i ) { matrix[i][j] += matrix[i - 1][j]; }
                if ( j ) { matrix[i][j] += matrix[i][j - 1]; }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int val = (*ptr)[row2][col2];
        if ( row1 && col1 ) { val += (*ptr)[row1 - 1][col1 - 1]; }
        if ( row1 ) { val -= (*ptr)[row1 - 1][col2]; }
        if ( col1 ) { val -= (*ptr)[row2][col1 - 1]; }
        
        return val;
    }
    
private:
    vector<vector<int>>* ptr;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
