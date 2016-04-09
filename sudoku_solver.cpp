//uri:	https://leetcode.com/problems/sudoku-solver/

/*
 *	如果直接暴力搜索，那么会超时，需要剪枝。我们可以把所有的非数字字符下标存储起来，
 *	每次遍历的时候就不会是遍历整个board；我们还需要进一步剪枝，把那些约束条件最多
 *	（也就是横向、纵向以及所在当前九宫格的约束条件综合起来）以至于每个字符'.'可选
 *	数字字符最少的下标位置处优先选择填放数字字符，加入队列。
 *	空间复杂度：O(未知).
 *	时间复杂度：O(未知).
 * */

class Solution {
public:
    class Node {
    public:
        vector<vector<char>> board;
        list<pair<int, int>> li;
        
        Node(vector<vector<char>> a, list<pair<int, int>> b) : board(a), li(b) { }
    };
    
    void solveSudoku(vector<vector<char>>& board) {
        queue<Node> q;
        q.push(init(board));
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            list<pair<int, int>>::iterator _itr = p.li.begin();
            if(_itr == p.li.end()) {
                board = p.board;
                return;
            }
            
            vector<char> minNums(10, 0);
            list<pair<int, int>>::iterator itr = _itr;
            for( ; itr != p.li.end(); ++ itr) {
                auto nums = count(p.board, itr -> first, itr -> second);
                if(nums.size() == 0) { break; }
                
                if(nums.size() < minNums.size()) {
                    minNums = nums;
                    _itr = itr;
                }
            }
            
            if(itr != p.li.end()) { continue; }
            
            int x = _itr -> first;
            int y = _itr -> second;
            p.li.erase(_itr);
            for(int i = minNums.size() - 1; i >= 0; -- i) {
                p.board[x][y] = minNums[i];
                q.push(p);
            }
        }
    }
    
    Node init(vector<vector<char>>& board){
        list<pair<int, int>> li;
        for(int i = 0; i < 9; ++ i) {
            for(int j = 0; j < 9; ++ j) {
                if(!isdigit(board[i][j])) { li.push_back(make_pair(i, j)); }
            }
        }
        
        return Node(board, li);
    }
    
    vector<char> count(vector<vector<char>>& board, int x, int y) {
        vector<char> nums;
        vector<bool> vis(10, 0);
        for(int i = 0; i < 9; ++ i) {
            if(isdigit(board[x][i])) { vis[board[x][i] - '0'] = true; }
            if(isdigit(board[i][y])) { vis[board[i][y] - '0'] = true; }
        }
        
        x = x / 3 * 3;
        y = y / 3 * 3;
        for(int i = 0; i < 3; ++ i) {
            for(int j = 0; j < 3; ++ j) {
                if(isdigit(board[x + i][y + j])) { vis[board[x + i][y + j] - '0'] = true; }
            }
        }
        
        for(int i = 1; i < 10; ++ i) {
            if(vis[i] == false) { nums.push_back('0' + i); }
        }
        
        return nums;
    }
};
