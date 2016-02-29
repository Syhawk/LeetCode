//uri:	https://leetcode.com/problems/reverse-words-in-a-string/

/*
 *	先将字符串内多余的空格剔除，然后再对整个字符串逆序，最后对每个单词逆序。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    void reverseWords(string &s) {
	    int len = s.size();
	    int cnt = 0;
        for(int i = 0, j = 0; i < len; i) {
            while(i < len && s[i] == ' ') ++ i;
            int pre = i;
            while(i < len && s[i] != ' ') ++ i;
            
            if(i > pre) {
                if(cnt) s[cnt ++] = ' ';
                for(int k = pre; k < i && k < len; ++ k)
                    s[cnt ++] = s[k];
            }
            
            if(i == len) for(int k = cnt; k < len; ++ k) s[k] = ' ';
        }
        
        eraseSpace(s);
        swapSubStr(s, 0, s.size() - 1);
        
        for(int i = s.size() - 1, pre = i; i >= -1; -- i) {
            if(i == -1 || s[i] == ' ') {
                swapSubStr(s, i + 1, pre);
                pre = i - 1;
            }
        }
    }
    
    void swapSubStr(string& s, int lhs, int rhs) {
        while(lhs < rhs) {
            swap(s[lhs ++], s[rhs --]);
        }
    }
    
    void eraseSpace(string& s) {
        int len = s.size();
        while(len && s[len - 1] == ' ') -- len;
        for(int i = s.size(); i > len; -- i) s.erase(s.end() - 1);
    }
};
