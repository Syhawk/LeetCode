//uri:	https://leetcode.com/problems/additive-number/

/*
 *	每次选取两个数，用二层循环来实现，然后再用第三层循环来检验。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n*n*n).(大约接近n*n,n*n*n应该达不到)
 * */

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(len < 3)
            return false;
        int bits = len / 2;
        for(int i = 1; i <= bits; ++ i) {
            long long x = stoll(num.substr(0, i));
            for(int j = 1; j <= bits; ++ j) {
                long long y = 0;
                int M = i;
                int actj = 1;
                if(num[i] != '0') {
                    y = stoll(num.substr(i, j));
                    M = max(M, j);
                    actj = j;
                }

                if(M > len - i - actj) continue;
                if(check(num, i + actj, len, x, y))
                    return true;
                if(y == 0) break;
            }
        }
        
        return false;
    }
    
    bool check(string& num, int i, int len, long long x, long long y) {
        for(; i < len; ) {
            y += x;
            string tmp = to_string(y);
            int j = 0;
            for(; tmp[j] && i + j < len && num[i + j] == tmp[j]; ++ j) ;
            if(tmp[j]) return false;
            x = y - x;
            i += j;
        }
        
        return true;
    }
};
