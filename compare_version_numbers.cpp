//uri:	https://leetcode.com/problems/compare-version-numbers/

/*
 *	对两个字符串版本比较大小，版本号由多节数字构成，所以需要每一节都需要比较大小。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        eraseZero(version1);
        eraseZero(version2);
        
        int i = 0, j = 0, prei = 0, prej = 0;
        while(version1[i] || version2[j]) {
            while(version1[i] && version1[i] != '.') ++ i;
            while(version2[j] && version2[j] != '.') ++ j;
            
            int result = compare(version1, prei, i, version2, prej, j);
            if(result != 0) return result;
            
            if(version1[i]) ++ i;
            if(version2[j]) ++ j;
            while(version1[i] && version1[i] == '0') ++ i;
            while(version2[j] && version2[j] == '0') ++ j;
            prei = i;
            prej = j;
        }
        
        return 0;
    }
    
    void eraseZero(string& s) {
        int len = s.size();
        int i = 0, k = 0;
        while(i < len && s[i] == '0') ++ i;
        
        for(int l = i; l < len; ++ l) {
            s[k ++] = s[l];
        }
        
        for( i = len; i > k; -- i)
            s.erase(s.end() - 1);
    }
    
    int compare(string& s1, int l1, int l2, string& s2, int r1, int r2) {
        if(l2 - l1 > r2 - r1) return 1;
        else if(l2 - l1 < r2 - r1) return -1;
        
        for(int i = l1, j = r1; i < l2 && j < r2; ++ i, ++ j) {
            if(s1[i] == s2[j]) continue;
            if(s1[i] > s2[j]) return 1;
            return -1;
        }
        
        return 0;
    }
};
