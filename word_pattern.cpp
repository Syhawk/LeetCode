//uri:	https://leetcode.com/problems/word-pattern/

/*
 *	判断字符串中pattern中的每个字符是否与str中的连续字符是否是一一映射关系。
 *	采用两个map容器，分别表示字符映射到字符串，字符串映射到字符，组合成一一映射，
 *	然后判断。
 *	空间复杂度：O(n + m).
 *	时间复杂度：O(nlogm).
 * */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len1 = pattern.size();
        int len2 = str.size();
        int cnt = 0;
        vector<string> strs;

        for(int i = 0, j = 0; i <= len2; ++ i)
        	if(str[i] == ' ' || i == len2) {
        		++ cnt;
        		strs.push_back(str.substr(j, i - j));
        		j = i + 1;
        	}

        if(cnt != len1) return false;

        map<char, string> m1;
        map<string ,char> m2;
        m1.clear();
        m2.clear();

        for(int i = 0; i < len1; ++ i) {
        	char ch = pattern[i];
        	if(m1.find(ch) == m1.end()) {
        		if(m2.find(strs[i]) != m2.end())
        			return false;
        		m1[ch] = strs[i];
        		m2[strs[i]] = ch;
        	}
        	else if(m1[ch] != strs[i] || m2[strs[i]] != ch) {
        		return false;
        	}
        }

        return true;
    }
};
