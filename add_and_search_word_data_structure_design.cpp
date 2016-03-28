//uri:	https://leetcode.com/problems/add-and-search-word-data-structure-design/

/*
 *	采用前缀树，方法有bfs和dfs两种，dfs耗时更少。
 *	空间复杂度：O(n*m).
 *	时间复杂度：O(n).
 * */

struct Node {
    bool end;
    Node* v[26];
    
    Node() : end(false) { memset(v, 0, sizeof v); }
};

class WordDictionary {
public:
    WordDictionary() { root = new Node(); }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        Node* ptr = root;
        for(int i = 0; word[i]; ++ i) {
            if(ptr -> v[word[i] - 'a'] == nullptr) { ptr -> v[word[i] - 'a'] = new Node(); }
            
            ptr = ptr -> v[word[i] - 'a'];
        }
        
        ptr -> end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return bfs(word);
        // return dfs(word, 0, root);
    }
    
    bool bfs(string& word) {
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if(word[p.second] == '\0') {
              if(p.first -> end) return true;
              continue;
            }
            
            if(word[p.second] == '.') {
                for(int i = 0; i < 26; ++ i) {
                    if(p.first -> v[i]) { q.push(make_pair(p.first -> v[i], p.second + 1)); }
                }
            } else {
                int index = word[p.second] - 'a';
                if(p.first -> v[index]) { q.push(make_pair(p.first -> v[index], p.second + 1)); }
            }
        }
        
        return false;
    }
    
    bool dfs(string& word, int index, Node* root) {
        if(root == nullptr) return false;
        if(word[index] == '\0') { return root -> end; }
        
        bool flg = false;
        if(word[index] == '.') {
            for(int i = 0; i < 26 && flg == false; ++ i) {
                flg |= dfs(word, index + 1, root -> v[i]);
            }
        } else { flg |= dfs(word, index + 1, root -> v[word[index] - 'a']); }
        
        return flg;
    }
    
private:
    Node* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
