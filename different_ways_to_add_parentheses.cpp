//uri:	https://leetcode.com/problems/different-ways-to-add-parentheses/

/*
 *	卡特兰数题目。每次将字符串分为两部分，分别得到两部分所有可能的结果，然后再对这些结果进行组合，得到当前字符串下所有可能的结果。
 *	（对每次求取结果进行存储，从而省去重复计算某一个字符串所需要的时间）
 *	空间复杂度：O(卡特兰数).
 *	时间复杂度：O(卡特兰数).
 * */

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        map<string, vector<int>> substr_to_result;
        
        return binaryCompute(input, substr_to_result);
    }
    
    vector<int> binaryCompute(string input, map<string, vector<int>>& substr_to_result) {
        if ( substr_to_result.find(input) != substr_to_result.end() ) { return substr_to_result[input]; }
        
        vector<int> result;
        int input_size = input.size();
        
        for ( int val = 0, i = 0; i < input_size; ++ i ) {
            if ( !isdigit(input[i]) ) { break; }
            val = val * 10 + (input[i] - '0');
            
            if (i == input_size - 1) {
                result.push_back(val);
                return substr_to_result[input] = result;
            }
        }
        
        for ( int i = 0; i < input_size; ++ i ) {
            if ( isdigit(input[i]) ) { continue; }
            char oper = input[i];
            vector<int> lhs_result = binaryCompute(input.substr(0, i), substr_to_result);
            vector<int> rhs_result = binaryCompute(input.substr(i + 1, input_size - (i + 1)), substr_to_result);
            
            for ( int lhs_result_index = lhs_result.size() - 1; lhs_result_index >= 0; -- lhs_result_index ) {
                for ( int rhs_result_index = rhs_result.size() - 1; rhs_result_index >= 0; -- rhs_result_index ) {
                    if ( oper == '*' ) { result.push_back(lhs_result[lhs_result_index] * rhs_result[rhs_result_index]); }
                    else if ( oper == '+' ) { result.push_back(lhs_result[lhs_result_index] + rhs_result[rhs_result_index]); }
                    else { result.push_back(lhs_result[lhs_result_index] - rhs_result[rhs_result_index]); }
                }
            }
        }
        
        return substr_to_result[input] = result;
    }
};
