//uri:	https://leetcode.com/problems/simplify-path/

/*
 *	简化路径，从前往后遍历，遇到"/./"或者"/.\0"就直接剔除"/."，遇到"/../"或者
 *	"/..\0"就剔除"/.."和此字符串前面的到'/'此字符位置的所有自符。剔除额外的连续
 *	的字符'/'。不能将一个字符串剔为空。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        if(size < 1) return path;
        
        int cnt = 0, k = 1;        
        for(int j = 1; j < size; ++ j) {
            if(path[j] != '/') path[k ++] = path[j];
            else if(path[k - 1] != '/') path[k ++] = path[j];
        }
        
        while(size > k) {
            path.erase(-- size);
        }
        while(-- k && path[k] == '/') {
            path.erase(k);
        }
        size = path.size();

        for(int i = 0; i <= size; ++ i) {
            if(path[i] == '.') ++ cnt;
            else {
                if((path[i] == '/' || path[i] == '\0') && cnt && cnt < 3)
                    change(i - 1, cnt, path);
                cnt = 0;
            }
        }
        
        string s = "";
        for(int i = 0; i < size; ++ i)
            if(path[i]) s += path[i];
        s += '/';
        size = s.size() - 1;
        while(size && s[size] == '/')
            s.erase(size --);
        
        return s;
    }
    
    void change(int i, int cnt, string& path) {
        for( ; i >= 0 && path[i] == '.'; -- i)
            path[i] = '\0';
        if(i >= 0) path[i] = '\0';
        
        if(cnt == 1) return;
        
        while(i >= 0 && path[i] == '\0') -- i;
        for( ; i >= 0 && path[i] != '/'; -- i)
            path[i] = '\0';
        if(i >= 0) path[i] = '\0';
    }
};
