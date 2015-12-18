//uri:	https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
 *	按照手机九宫格给出按下的数字，返回所有可能的字母组合。
 *	采用宽度优先遍历方式，找出所有可能组合存储并返回。
 *	空间复杂度：O(n^3).
 *	时间复杂度：O(n^3).
 * */

vector<string> strs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        v.clear();
        string* s = &digits;
        for(int i = 0; (*s)[i]; ++ i) {
            if((*s)[i] >= '2' && (*s)[i] <= '9')
                continue;
            else
                return v;
        }
        if((*s).size() < 1) return v;

        queue<pair<string, int>> q;
        int index = (*s)[0] - '2';
        string tmp = "";
        for(int i = 0; strs[index][i]; ++ i)
            q.push(make_pair(tmp + strs[index][i], 0));
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int index = p.second + 1;
            tmp = p.first;
            if(!(*s)[index]) {
                v.push_back(tmp);
                continue;
            }

            int pos = (*s)[index] - '2';
            for(int i = 0; strs[pos][i]; ++ i) {
                q.push(make_pair(tmp + strs[pos][i], index));
            }
            
        }

        return v;
    }
};
