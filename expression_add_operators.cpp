//uri:	https://leetcode.com/problems/expression-add-operators/

/*
 *	深度优先遍历，对于当前元素值有+,-,*三种操作可选，-相当于+一个负数，*相当于+上一堆连续相乘的数。
 *	所以，采用一个额外的变量存储上一步操作最后一项的值。如果当前选择是+或者-，那么直接用当前加的值作为最后一项，否则就把上次操作的最后一项
 *	乘以当前的项作为最后一项传递给下层操作。
 *	空间复杂度：O(3^n).
 *	时间复杂度：O(3^n).
 * */

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        _target = target;
        long val = 0;
        
        for ( int i = 0; num[i]; ++ i ) {
            val = val * 10 + num[i] - '0';
            dfs(num, i + 1, num.substr(0, i + 1), val, val);
            if ( num[0] == '0' ) { break; }
        }
        
        return result;
    }
    
    void dfs(string& num, int index, string express, long out, long preout) {
        if ( num[index] == '\0' ) {
            if ( out == _target ) { result.push_back(express); }
            return;
        }
        
        long val = 0;
        string s = "";
        for ( int i = index; num[i]; ++ i ) {
            val = val * 10 + num[i] - '0';
            s += num[i];
            
            dfs(num, i + 1, express + '*' + s, out - preout + preout * val, preout * val);
            dfs(num, i + 1, express + '-' + s, out - val, -val);
            dfs(num, i + 1, express + '+' + s, out + val, val);
            
            if ( num[index] == '0' ) { return; }
        }
    }

private:
    int _target;
    vector<string> result;
};
