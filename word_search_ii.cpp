//uri:	https://leetcode.com/problems/word-search-ii/

/*
 *	将所有的words用前缀树来表示，然后遍历board，在前缀树中查找所有可能的结果，如果在前缀树中找到了某个单词，那么，就把这个单词从前缀树中删除。
 *	空间复杂度：O(max(n * m, 26 * len * k)).
 *	时间复杂度：O(n * m * len).
 * */

class Solution {
public:
    struct Tree {
        bool isWord;
        vector<Tree*> next;
        Tree() : isWord(false), next(vector<Tree*>(26, nullptr)) {}
    };
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Tree* root = new Tree();
        for ( int i = 0; i < words.size(); ++ i ) { insert(root, words[i]); }
        
        vector<string> result;
        string word = "";
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));
        for ( int i = 0; i < board.size(); ++ i ) {
            for ( int j = 0; j < board[i].size(); ++ j ) {
                findWord(board, i, j, word, vis, root, result);
            }
        }
        
        return result;
    }
    
    void findWord(vector<vector<char>>& board, int x, int y, string& word, vector<vector<bool>>& vis, Tree* root, vector<string>& result) {
        if ( x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || vis[x][y] ) { return; }
        
        int index = board[x][y] - 'a';
        root = root -> next[index];
        if ( root == nullptr ) { return; }
        vis[x][y] = true;
        
        word += board[x][y];
        if ( root -> isWord ) {
            result.push_back(word);
            root -> isWord = false;
        }
        
        for ( int i = 0; i < 4; ++ i ) {
            findWord(board, x + dir[i][0], y + dir[i][1], word, vis, root, result);
        }
        
        word.erase(word.size() - 1, 1);
        vis[x][y] = false;
    }
    
    void insert(Tree* root, string& word) {
        for ( int i = 0; word[i]; ++ i ) {
            int index = word[i] - 'a';
            
            if ( root -> next[index] == nullptr ) { root -> next[index] = new Tree(); }
            root = root -> next[index];
        }
        
        root -> isWord = true;
    }
};
