//uri:	https://leetcode.com/problems/count-primes/

/*
 *	根据本题描述，给出以下四种方式，时间消耗依次增加，最下面一种耗时最少。
 *	空间复杂度：O(未知).
 *	时间复杂度：O(未知).
 * */

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        int cnt = 0;
        for(int i = 2; i < n; ++ i) {
            int j = 2;
            int m = sqrt(i + 0.5);
            while(j <= m && i % j != 0) ++ j;
            if(j > m) cnt += 1;
        }
        
        return cnt;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 2; i < n; ++ i) {
            if(!vis[i]) cnt += 1;
            if(i != i * i / i) continue;
            for(int j = i * i; j < n; j += i)
                vis[j] = true;
        }
        
        return cnt;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<bool> vis(n, false);
        int m = sqrt(n + 0.5);
        for(int i = 2; i <= m; ++ i) {
            if(vis[i]) continue;
            for(int j = i; i * j < n; ++ j) vis[i * j] = true;
        }
        
        int cnt = 0;
        for(int i = 2; i < n; ++ i)
            if(!vis[i]) cnt += 1;
        
        return cnt;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        
        vector<bool> vis(n, false);
        vector<int> prime;
        int len = 0;
        for(int i = 2; i < n; ++ i) {
            if(!vis[i]) {
                prime.push_back(i);
                len += 1;
            }
            
            for(int j = 0; j < len && i * prime[j] < n; ++ j) {
                vis[i * prime[j]] = true;
                if(i % prime[j] == 0) break;
            }
                
        }
        
        return len;
    }
};
