//uri:	https://leetcode.com/problems/permutation-sequence/

/*
 *	直接枚举所有排列会超时。所以根据其各个数字皆不同的性质直接计算出排列组合。
 *	假设一初始数列为：1、2、3、4、...、n。如果变换到2、3、4、5、1、...、n则变换了
 *	5！次即k - 1次，那么变换到3、4、5、2、1、...、n则变换了5！ + 4！次（减一是因为
 *	初始化的最小序列是变换了0次，为这个时候k为1）。所以，k就可以看成:
 *	k = a1 * x1! + a2 * x2! + a3 * x3! + ... + an & xn! + 1。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n*n).
 * */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        v.clear();
        int i = 1;
        for( i = n; i > 0; -- i ) {
            v.push_back(i);
        }
        
        if(n <= 1) return "1";
        
        long m = 1;
        -- k;
        for( i = 1; k >= m; m *= ++ i) ;
        m /= i --;
        
        while(k) {
            int x = k / m;
            k %= m;
            int t = v[i - x];
            for(int j = i - x + 1; j <= i; ++ j)
                v[j - 1] = v[j];
            v[i] = t;
            
            m /= i --;
        }
        
        string s = "";
        for( i = n - 1; i >= 0; -- i)
            s += to_string(v[i]);
        
        return s;
    }
};
