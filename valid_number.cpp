//uri:	https://leetcode.com/problems/valid-number/

/*
 *	根据所有可能出现的情况进行排除。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int j = s.size() - 1;
        for ( ; i <= j && s[i] == ' '; ++ i );
        for ( ; j >= i && s[j] == ' '; -- j );
        
        if ( i > j ) { return false; }
        if ( s[i] == '+' || s[i] == '-' ) { ++ i; }
        
        bool digit = false;
        for ( ; i <= j && isdigit(s[i]); ++ i ) { digit = true; }
        
        bool point = false;
        bool base = false;
        if ( i > j ) { return digit; }
        if ( s[i] == '.' || s[i] == 'e' ) {
            if ( s[i] == '.' ) { point = true; }
            else { base = true; }
            
            if ( !digit && base ) { return false; }
            ++ i;
        }
        else { return false; }
        
        if ( point ) {
            for ( ; i <= j && isdigit(s[i]); ++ i ) { digit = true; }
            if ( i > j ) { return digit; }
            if ( s[i] == 'e' ) {
                ++ i;
                base = true;
            }
        }
        
        if ( !base ) { return false; }
        if ( i > j ) { return false; }
        if ( !digit ) { return false; }
        
        digit = false;
        if ( s[i] == '+' || s[i] == '-' ) { ++ i; }
        for ( ; i <= j && isdigit(s[i]); ++ i) { digit = true; }
        
        if ( i <= j ) { return  false; }
        if ( !digit ) { return false; }
        
        return true;
    }
};
