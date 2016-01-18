//uri:	https://leetcode.com/problems/decode-ways/

/*
 *	解码首先需要判断一下字符'0',因为这个字符比较特别，连续两个字符'0'存在就没法
 *	再解码，而且，一旦存在一个该字符，那么其前面一个字符必须要与之组合解码。
 *	剩下的解码如果进行解码"1111"：
 *	一个字符只能解码为："1"
 *	两个字符能够解码为："1 1"和"11"
 *	三个字符能够解码为："1 1 1"、"1 11"和"11 1"
 *	四个字符能够解码为："1 1 1 1"、"1 1 11"、"1 11 1"、"11 1 1"和"11 11"
 *	通过以上分析可以发现："1"根据下一个字符情况，分解为了"1 1"和"11"
 *	而，"1 1"和"11"再通过下一个字符分别分解成了"1 1 1"、"1 11"和"11 1"。
 *	可得以后的字符分解都是通过上一个字符的情况进行分解的。
 *	然而，当当前字符与下一个字符进行组合发现不可分解的时候，那么只能全都成为
 *	单一分解一个字符。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int numDecodings(string s) {
        int len = 0;
        int flg = 0;
        for(int i = 0; s[i]; ++ i) {
            if(s[i] == '0') len -= 1, flg = 1;
            else s[len ++] = s[i];
            
            if(i && s[i] == '0' && s[i - 1] == '0') return 0;
            if(len < 0) return 0;
            if(i &&  s[i] == '0' && s[i - 1] > '2') return 0;
        }
        if(len < 1) return flg;
        
        int sigl = 0, dol = 1;
        int t = 1;
        if(s[0] > '2') swap(sigl, dol);
        for(int i = 1; i < len; ++ i) {
            int x = (s[i - 1] - '0') * 10 + s[i] - '0';
            
            if(x < 27) {
                if(sigl == 0) swap(sigl, dol);
                t = sigl * 2 + dol;
                dol += sigl;
                swap(sigl, dol);
            } else {
            	t = sigl + dol;
            	dol += sigl;
            	sigl = 0;
            }

        }
        
        return t;
    }
};
