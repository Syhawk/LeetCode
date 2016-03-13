//uri:	https://leetcode.com/problems/repeated-dna-sequences/

/*
 *	因为只存在四种字符，所以可以用00,01,10,11分别表示，那么，一个字符串将可以被
 *	二进制数表示出来。因为要取十个字符，就是相当于取20位二进制数，把这些二进制数
 *	存储起来，最后，将出现次数多于一次的皆转化为字符输出出来。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> mp;
        vector<string> v;
        const int N = 0xfffff;
        
        int sum = 0;
        for(int i = 0; s[i]; ++ i) {
            sum <<= 2;
            switch(s[i]) {
                case 'T' :
                    sum += 1;
                    break;
                case 'C' :
                    sum += 2;
                    break;
                case 'G' :
                    sum += 3;
                    break;
            }
            
            sum &= N;
            
            if(i < 9) continue;
            if(mp.find(sum) == mp.end()) {
                mp[sum] = 1;
                continue;
            }
            
            if(mp[sum] == 1) v.push_back(s.substr(i - 9, 10));
            mp[sum] += 1;
        }
        
        return v;
    }
};
