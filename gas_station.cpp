//uri:	https://leetcode.com/problems/gas-station/

/*
 *	需要循环一遍，那么开始位置一定是从gas[i] - cost[i]非负的位置开始，到某一个
 *	位置结束。如果这个位置不是刚开始出发的位置，那么，下一次出发的位置就是当前
 *	结束位置的下一个位置。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for(int i = 0; i < len; ++ i)
            gas[i] -= cost[i];
        for(int i = 0; i < len - 1; ++ i)
            gas.push_back(gas[i]);
        
        for(int i = 0; i < len; ) {
            int j = i + len, k = i;
            for(int sum = 0; k < j; ++ k) {
                sum += gas[k];
                if(sum < 0) break;
            }
            
            if(k == j) return i;
            i = k + 1;
        }
        
        return -1;
    }
};
