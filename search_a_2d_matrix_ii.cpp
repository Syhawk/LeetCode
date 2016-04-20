//uri:	https://leetcode.com/problems/search-a-2d-matrix-ii/

/*	把二维数组分成四部分，分别查找目标值。
 *	空间复杂度：O(1).
 *	时间复杂度：O(max(m, n)log(max(m, n))).
 * */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
    bool search(vector<vector<int>>& matrix, 
                int up_left_x,
                int up_left_y,
                int down_right_x,
                int down_right_y,
                int target) {
        if ( down_right_x < up_left_x || down_right_y < up_left_y ) { return false; }
        if ( down_right_x == up_left_x && down_right_y == up_left_y ) { return matrix[up_left_x][up_left_y] == target; }
        if ( matrix[up_left_x][up_left_y] > target || matrix[down_right_x][down_right_y] < target ) { return false; }
        
        int mid_x = (up_left_x + down_right_x) >> 1;
        int mid_y = (up_left_y + down_right_y) >> 1;
        if ( matrix[mid_x][mid_y] == target ) { return true; }
        
        return search(matrix, up_left_x, up_left_y, mid_x, mid_y, target)
            || search(matrix, mid_x + 1, mid_y + 1, down_right_x, down_right_y, target)
            || search(matrix, up_left_x, mid_y + 1, mid_x, down_right_y, target)
            || search(matrix, mid_x + 1, up_left_y, down_right_x, mid_y, target);
    }
};
