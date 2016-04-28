//uri:	https://leetcode.com/problems/super-ugly-number/

/*
 *	超级丑数是指一个数的约数只能是1或者给定的素数。
 *	做法与三个素数的丑数一致：找出最小的丑数，然后与得到这个丑数的所有其他素数的下标右移。
 *	空间复杂度：O(n + m).
 *	时间复杂度：O(n * m).
 * */

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> indices(primes.size(), 0);
        vector<long> vals(1, 1);
        for ( int k = 1; k < n; ++ k ) {
            long min_val = primes[0] * vals[indices[0]];
            for ( int i = 1; i < primes.size(); ++ i ) { min_val = min(min_val, primes[i] * vals[indices[i]]); }
            
            vals.push_back(min_val);
            
            for ( int i = 0; i < primes.size(); ++ i ) {
                if ( primes[i] * vals[indices[i]] == min_val ) { ++ indices[i]; }
            }
        }
        
        return vals[n - 1];
    }
};
