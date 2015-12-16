//uri:	https://leetcode.com/problems/longest-common-prefix/

/*
 *	对字符串向量采用列遍历方式，如果此列的字符均相同，
 *	则将此字符加入最长公共前缀字符串，并判断下一列；
 *	否则遍历终止，返回当前最长公共字符串。
 *	注：假设字符串向量中最长字符串为长度n，字符串个数为m。
 *	空间复杂度：O(n).
 *	时间复杂度：O(m * n).
 * */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        bool flg = true;
        int size = strs.size();
        for(int j = 0; flg; ++ j) {
            char ch = 0;
            flg = 0;
            for(int i = 0; i < size; ++ i) {
                auto p = &strs[i];
                if(p -> size() <= j)  {
                    flg = 0;
                    break;
                } else if(ch == '\0') {
                    ch = (*p)[j];
                    flg = 1;
                }
                else if(ch != (*p)[j]) {
                    flg = 0;
                    break;
                }
            }
            if(flg && ch)
                s += ch;
        }
        return s;
    }
};
