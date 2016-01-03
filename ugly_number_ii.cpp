//uri:	https://leetcode.com/problems/ugly-number-ii/

/*
 *	预处理求出所有的ugly number，然后每次返回nth个ugly number即可。
 *	求出所有ugly number就用基数2、3、5直接在原来的ugly number基础上相乘，
 *	每次选出最小的一个存储。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

bool flg = false;
vector<int> ugly;
#define inf 0x7fffffff

void init() {
    ugly.clear();
    ugly.push_back(1);
    int i = 0, j = 0, k = 0;
    
    while(1) {
        int x = 2 * ugly[i];
        int y = 3 * ugly[j];
        int z = 5 * ugly[k];
        if(x % 2 != 0 || x / 2 != ugly[i]) x = inf;
        if(y % 3 != 0 || y / 3 != ugly[j]) y = inf;
        if(z % 5 != 0 || z / 5 != ugly[k]) z = inf;

        int minimum = min(min(x, y), z);

        if(minimum == inf) break;
        ugly.push_back(minimum);

        if(minimum == x) ++ i;
        if(minimum == y) ++ j;
        if(minimum == z) ++ k;
    }

    flg = true;
}

class Solution {
public:
    int nthUglyNumber(int n) {
        if(!flg) init();
        return ugly[n - 1];
    }
};
