//uri:	https://leetcode.com/problems/rotate-image/

/*
 *	因为要求原地转换，通过观察发现旋转90度一个点的变化会引起另外三个点的变化。
 *	因此，假设图像的长、宽为n，那么，可以得到如下变化：
 *	(i, j) -> (j, n - 1 - i) -> (n - 1 - i, n - 1 - j) -> (n - 1 - j, i) -> (i, j)
 *	以上就是变化的规律。由于每次变化四个点，所以，在循环的时候需要注意不能再次变化
 *	已经变化了的点。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n^2).
 * */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++ i)
            for(int j = i; j < n - i - 1; ++ j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
    }
};
