//uri:	https://leetcode.com/problems/perfect-squares/

/*
 *	预处理后台数据可能达到的最大数值，然后每次直接返回结果。
 *	预处理用dp来实现：dp(i) = min(dp(i), dp(i - square) + 1)。
 *	空间复杂度：O(1e5).
 *	时间复杂度：O(1e7).
 * */

bool flg = false;
int cnt[100000];

void init() {
    memset(cnt, 0x1, sizeof cnt);
    cnt[0] = 0;
    for(int i = 1; i <= 316; ++ i ) {
        int sq = i * i;
        for(int j = sq; j < 100000; ++ j) {
            cnt[j] = min(cnt[j], cnt[j - sq] + 1);
        }
    }
        
    flg = true;
}

class Solution {
public:
    int numSquares(int n) {
        if(!flg) init();
        return cnt[n];
    }
};

