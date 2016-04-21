//uri:	https://leetcode.com/problems/text-justification/

/*
 *	根据规则进行相应的位置变换，最后一行都是左对齐，剩下的均是均匀对齐（单个单词是左对齐）。
 *	空间复杂度：O(n * maxWidth)
 *	时间复杂度：O(n * maxWidth)
 * */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text;
        int len = words.size();
        for ( int i = 0; i < len; ++ i ) {
            int width = 0;
            int j = i;
            for ( ; j < len; ++ j ) {
                int word_length = words[j].size();
                width += word_length;
                
                if ( width + (j - i) > maxWidth ) {
                    width -= word_length;
                    break;
                }
            }
            
            int spaces = maxWidth - width;
            int even_spaces = spaces;
            if ( j - i - 1 ) { even_spaces = spaces / ( j - i - 1 ); }
            int left_spaces = 0;
            if ( j - i - 1 ) { left_spaces = spaces % ( j - i - 1 );}
            string s = "";
            for ( int k = i; k < j; ++ k ) {
                s += words[k];
                if ( j >= len && spaces) {
                    s += ' ';
                    spaces -= 1;
                    continue;
                }
                for ( int space = 0; space < even_spaces && spaces; ++ space, -- spaces ) { s += ' '; }
                if ( left_spaces ) {
                    s += ' ';
                    left_spaces -= 1;
                    spaces -= 1;
                }
            }
            
            if ( j >= len && spaces) {
                while ( spaces -- ) { s += ' '; }
            }
            text.push_back(s);
            i = j - 1;
        }
        
        return text;
    }
};
