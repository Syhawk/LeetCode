//uri:	https://leetcode.com/problems/search-a-2d-matrix/

/*
 *	每一行都是有序的，可以采用二分查找
 *	空间复杂度：O(1).
 *	时间复杂度：O(mlogn).
 * */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size() - 1;
        
        for(int i = 0; i < m && matrix[i][0] <= target; ++ i) {
            if(find(matrix[i], n, target)) return true;
        }
        
        return false;
    }
    
    bool find(vector<int>& row, int len, int target) {
        if(row[len] < target) return false;
        
        int left = 0, right = len;
        while(left <= right) {
            int mid = ((right - left) >> 1) + left;
            
            if(row[mid] == target) return true;
            if(row[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return false;
    }
};
