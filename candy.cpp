//uri:	https://leetcode.com/problems/candy/

/*
 *	每次查找最大的连续递增序列，然后再查找对应的最大连续递减序列，其中，波峰的取值为最大序列（递增或者递减）
 *	的个数。所求的candy数为：递增序列和 + 波峰值 + 递减序列和
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        for ( int i = 0; i < ratings.size(); ) {
            int init_index = i;
            while ( i + 1 < ratings.size() && ratings[i] < ratings[i + 1] ) { ++ i; }
            int max_index = i;
            while ( i + 1 < ratings.size() && ratings[i] > ratings[i + 1] ) { ++ i; }
            
            sum += (max_index - init_index + 1) * (max_index - init_index) / 2;
            sum += max(i - max_index, max_index - init_index) + 1;
            sum += (i - max_index + 1) * (i - max_index) / 2;
            
            if ( i != max_index ) { sum -= 1; }
            if ( i == max_index ) { ++ i; }
        }
        
        return sum;
    }
};
