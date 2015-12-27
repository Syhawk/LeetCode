//uri:	https://leetcode.com/problems/bulls-and-cows/

/*
 *	根据secret和guess给出猜中多少个bull和cow的提示。
 *	首先判断bull猜中多少个，那么把secret[i] == guess[i]相等的数目相加；
 *	剩下的不相等的guess存储道另一个字符串s中，并统计剩下的secret中的数字字符
 *	数目放到num中；然后再次循环判断s中每存在一个数字字符且num中包含此字符的数目
 *	不为空，那么就cow数目就增加一次。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    string getHint(string secret, string guess) {
        string g = "";
        int b = 0, c = 0;
        int num[10];
        memset(num, 0, sizeof num);
        for(int i = 0; i < secret.size(); ++ i)
            if(secret[i] == guess[i]) ++ b;
            else {
                ++ num[secret[i] - '0'];
                g += guess[i];
            }
            
        for(int i = 0; i < g.size(); ++ i) {
            int x = g[i] - '0';
            if(num[x]) {
                ++ c;
                -- num[x];
            }
        }
        
        return to_string(b) + "A" + to_string(c) + "B";
    }
};
