//uri:	https://leetcode.com/problems/restore-ip-addresses/

/*
 *	ip地址字符串的长度必须是在4-12范围之内，所以空间复杂度与时间复杂度均为常量。
 *	ip地址中存在0，所以需要特判。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        int len = s.size();
        if(len > 12 || len < 4) return v;

        for(int i = 0; i < len - 3 && i < 3; ++ i) {
            if(!cal(0, i, s)) continue;
            
            for(int j = i + 1; j < len - 2 && j - i < 4  && len - i - 1 >= 3 && len - i - 1 <= 9; ++ j) {
                if(!cal(i + 1, j, s)) continue;
                
                for(int k = j + 1; k < len - 1 && k - j < 4 && len - j - 1 >= 2 && len - j - 1 <= 6; ++ k) {
                    if(len - k - 1 > 3 || !cal(j + 1, k, s) || !cal(k + 1, len - 1, s)) continue;
                    
                    v.push_back(s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + s.substr(j + 1, k - j) + "." + s.substr(k + 1, len - k - 1));
                }
            }
        }
        
        return v;
    }
    
    bool cal(int l, int r, string& s) {
        if(s[l] == '0' && r - l != 0) return false;
        int x = 0;
        for(int i = l; i <= r; ++ i) {
            x = (s[i] - '0') + x * 10;
        }
        
        if(x < 256) return true;
        return false;
    }
};
