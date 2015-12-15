https://leetcode.com/problems/valid-sudoku/

/*
 *	判断数独是否有效，省略字符','，仅关心1-9的数字。判断每一行，每一列，
 *	每个9*9的正方形不存在重复数字即可。正方形不是任意一个正方形。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		ptr = &board;
        const int N = 9;
		bool flg = true;
        for(int i = 0; i < N && flg; ++ i) {
            for(int j = 0; j < N && flg; ++ j) {
				if(j == 8) flg = check(i, i, 0, 8);
				if(i == 8 && flg) flg = check(0, 8, j, j);
				if(i % 3 == 2 && j % 3 == 2 && flg)
					flg = check(i - 2, i, j - 2, j);
				}
            }
        
        return flg;
    }
    
    bool check(int ils, int irs, int jls, int jrs) {
        bool vis[10] = {};
		char ch;
        for(int i = ils; i <= irs; ++ i)
            for(int j = jls; j <= jrs; ++ j) {
				ch = (*ptr)[i][j];
                if(!isdigit(ch)) continue;
                
                int d = ch - '0';
                if(vis[d]) return false;
                vis[d] = true;
            }
            
        return true;
    }

private:
	vector<vector<char>>* ptr;
};
