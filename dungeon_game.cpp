//uri:	https://leetcode.com/problems/dungeon-game/

/*
 *	采用二分查找 + dp,由于需要设定一个最小的生命值，这个生命值的范围是正整数范围，所以可以采用二分查找，
 *	选定的生命值是否符合条件，采用dp来判断。
 *	空间复杂度：O(n).
 *	时间复杂度：O(m * n * 32).
 * */

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int min_life = 1;
        int max_life = 0;
        int sum = 0;
        for ( int i = 0; i < dungeon.size(); ++ i ) {
            sum += dungeon[i][0];
            max_life = min(max_life, sum);
        }
        
        for ( int i = 1; i < dungeon[0].size(); ++ i ) {
            sum += dungeon[dungeon.size() - 1][i];
            max_life = min(max_life, sum);
        }
        
        max_life = -max_life + 1;
        
        while ( min_life < max_life ) {
            int mid_life = (min_life + max_life) >> 1;
            
            if ( getDp(dungeon, mid_life) ) { max_life = mid_life; }
            else { min_life = mid_life + 1; }
        }
        
        return min_life;
    }
    
    bool getDp(vector<vector<int>>& dungeon , int life) {
        vector<int> dp(dungeon[0].size(), 0);
        dp[0] = life;
        
        for ( int i = 0; i < dungeon.size(); ++ i ) {
            if ( dp[0] > 0 ) { dp[0] += dungeon[i][0]; }
            
            for ( int j = 1; j < dungeon[i].size(); ++ j ) {
                if ( dp[j] > 0 || dp[j - 1] > 0 ) { dp[j] = max(dp[j], dp[j - 1]) + dungeon[i][j]; }
            }
        }

        return dp[dungeon[0].size() - 1] > 0;
    }
};
