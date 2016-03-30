//uri:	https://leetcode.com/problems/implement-trie-prefix-tree/

/*
 *	根据所给出框架，实现前缀树。
 *	空间复杂度：O(未知).
 *	时间复杂度：O(n).
 * */

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : ch(0), isWord(false) { memset(nodes, 0, sizeof nodes); }
    
    TrieNode(char c) : ch(c), isWord(false) { 
		memset(nodes, 0, sizeof nodes); 
	}
    
    void setIsWord(bool isWord) { this -> isWord = isWord; }
    
    bool getIsWord() { return isWord; }
   
	TrieNode** getNodes() { return nodes; }
private:
    char ch;
    bool isWord;
    TrieNode* nodes[26];
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    // Inserts a word into the trie.
    void insert(string word) {
        int len = word.size();
        if(len == 0) root -> setIsWord(true);
        
        TrieNode* ptr = root;
        for(int i = 0; i < len; ++ i) {
            if(!ptr -> getNodes()[word[i] - 'a']) { ptr -> getNodes()[word[i] - 'a'] = new TrieNode(word[i]); }

	        ptr = ptr -> getNodes()[word[i] - 'a'];
		
            if(i == len - 1) { ptr -> setIsWord(true); }            
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        int len = word.size();
        if(len == 0) { return ptr -> getIsWord(); }
        int i = 0;
        for( ; i < len && ptr; ++ i) { ptr = ptr -> getNodes()[word[i] - 'a']; }
        
        return (i == len && ptr && ptr -> getIsWord());
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        int len = prefix.size();
        int i = 0;
        for( ; i < len && ptr; ++ i) { ptr = ptr -> getNodes()[prefix[i] - 'a']; }
        
        return (i == len && ptr);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
