//uri:	https://leetcode.com/problems/word-search/

/*
 *	在一个二维字符串中查找一个一维字符串，这个一维字符串在二维字符串中必须是从一个
 *	字符开始，然后从这个字符的上、下、左、右四个位置查找下一个字符，这下一个字符
 *	又作为新的起点查找下一个字符...直至找完整个一维字符串，表明该二维字符串中存在
 *	该一维字符串。
 *	空间复杂度：O(1).
 *	时间复杂度：O(m*n).
 * */

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for(int i = 0; i < row; ++ i)
            for(int j = 0; j < col; ++ j) {
                if(dfs(i, j, board, 0, word)) return true;
            }
            
        return false;
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, int index, string& word) {
        if(word[index] == '\0') return true;
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        if(word[index] != board[i][j]) return false;
        char ch = board[i][j];
        board[i][j] = '\0';
        
        for(int k = 0; k < 4; ++ k) {
            if(dfs(dir[k][0] + i, dir[k][1] + j, board, index + 1, word)) return true;
        }
        
        board[i][j] = ch;
        
        return false;
    }

private:
    int row, col;
};
