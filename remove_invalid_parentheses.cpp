//uri:	https://leetcode.com/problems/remove-invalid-parentheses/

/*
 *	方法一：判断每一个括号删除之后是否接近于所有括号匹配，如果是，加入队列，否则不删除该括号
 *	方法二：字符串中出现括号不匹配最多有左括号偏多和右括号偏多两种情况，针对两种情况，进行括号删除。
 *	空间复杂度：O(n!).
 *	时间复杂度：O(n!).
 * */

class Solution {
public:
    struct Node {
        string str;
        int index;
        pair<int, int> error;
        Node(string& a, int b, pair<int, int> c) : str(a), index(b), error(c) {}
    };
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        queue<Node> q;
        unordered_set<string> _set;
        string lhs = "";
        string rhs = "";
        int left = 0;
        int right = s.size() - 1;
        
        for ( ; s[left] && s[left] != '('; ++ left ) {
            if ( s[left] != ')' ) { lhs += s[left]; }
        }
        
        for ( ; right > left && s[right] != ')'; -- right ) {
            if ( s[right] != '(' ) { rhs += s[right]; }
        }
        for ( int i = 0, j = rhs.size() - 1; i < j; ++ i, -- j ) { swap(rhs[i], rhs[j]); }
        
        s = s.substr(left, right - left + 1);
        q.push(Node(s, 0, cntParenthes(s)));
        while ( !q.empty() ) {
            auto p = q.front();
            q.pop();
            
            if ( p.error.first + p.error.second == 0 ) {
                result.push_back(lhs + p.str + rhs);
                continue;
            }
            
            for ( int i = p.index; p.str[i]; ++ i ) {
                while ( p.str[i] && p.str[i] != '(' && p.str[i] != ')' ) { ++ i; }
                
                if ( i == p.str.size() ) { break; }
                
                string ch = "";
                ch += p.str[i];
                p.str.erase(i, 1);
                
                auto error = cntParenthes(p.str);
                if ( isValid(p.error.first - error.first, p.error.second - error.second) && _set.find(p.str) == _set.end() ) {
                    _set.insert(p.str);
                    q.push(Node(p.str, i, error));
                }
                
                p.str.insert(i, ch);
            }
        }
        
        return result;
    }
    
    pair<int, int> cntParenthes(string& s) {
        int cntLhs = 0;
        int cntRhs = 0;
        int errorLhs = 0;
        int errorRhs = 0;
        for ( int i = 0, j = s.size() - 1; s[i]; ++ i, -- j ) {
            if ( s[i] == '('  ) { cntLhs += 1; }
            else if ( s[i] == ')' ) {
                if ( cntLhs ) { cntLhs -= 1; }
                else { errorLhs += 1; }
            }
            
            if ( s[j] == ')' ) { cntRhs += 1; }
            else if ( s[j] == '(' ) {
                if ( cntRhs ) { cntRhs -= 1; }
                else { errorRhs += 1; }
            }
        }
        
        return make_pair(errorLhs, errorRhs);
    }
    
    bool isValid(int lhs, int rhs) { return lhs >= 0 && rhs >= 0; }
};

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        string lhs = "";
        int lower_bound = 0;
        while ( s[lower_bound] && s[lower_bound] != '(' ) {
            if ( s[lower_bound] != ')' ) { lhs += s[lower_bound]; }
            ++ lower_bound;
        }
        
        string rhs = "";
        int upper_bound = s.size() - 1;
        while ( upper_bound >= lower_bound && s[upper_bound] != ')' ) {
            if ( s[upper_bound] != '(' ) { rhs += s[upper_bound]; }
            -- upper_bound;
        }
        
        for ( int i = 0, j = rhs.size() - 1; i < j; ++ i, -- j ) { swap(rhs[i], rhs[j]); }
        
        int cnt = 0;
        vector<int> left;
        for ( int i = lower_bound; i <= upper_bound; ++ i ) {
            if ( s[i] == '(' ) { cnt += 1; }
            else if ( s[i] == ')' ) {
                if ( cnt ) { cnt -= 1; }
                else { left.push_back(i); }
            }
        }
        
        cnt = 0;
        vector<int> right;
        for ( int i = upper_bound; i >= lower_bound; -- i ) {
            if ( s[i] == ')' ) { cnt += 1; }
            else if ( s[i] == '(' ) {
                if ( cnt ) { cnt -= 1; }
                else { right.push_back(i); }
            }
        }
        
        unordered_set<string> _set;
        vector<string> lhs_cnt;
        string substr = "";
        dfsLhs(lhs_cnt, substr, lower_bound, 0, left, s, _set);
        
        vector<string> rhs_cnt;
        substr = "";
        _set.clear();
        dfsRhs(rhs_cnt, substr, upper_bound, 0, right, s, _set);
        
        int l = lower_bound;
        int r = upper_bound + 1;
        if ( left.size() ) { l = left[left.size() - 1] + 1; }
        if ( right.size() ) { r = right[right.size() - 1]; }
        string mid = s.substr(l, r - l);

        vector<string> result;
        for ( int i = 0; i < lhs_cnt.size(); ++ i ) {
            for ( int j = 0; j < rhs_cnt.size(); ++ j ) {
                result.push_back(lhs + lhs_cnt[i] + mid + rhs_cnt[j] + rhs);
            }
        }
        
        return result;
    }
    
    void dfsLhs(vector<string>& _cnt, string substr, int index, int rest, vector<int>& bound, string& s, unordered_set<string>& _set) {
        if ( rest == bound.size() ) {
            if ( bound.size() ) { substr += s.substr(index, bound[bound.size() - 1] - index + 1); }
            if ( _set.find(substr) != _set.end() ) { return; }
            _set.insert(substr);
            _cnt.push_back(substr); 
            return;
        }
        
        if ( index == bound[rest] ) { dfsLhs(_cnt, substr, index + 1, rest + 1, bound, s, _set); }
        for ( int i = index; i < bound[rest]; ++ i ) {
            while ( i < bound[rest] && s[i] != ')' ) { substr += s[i ++]; }
            dfsLhs(_cnt, substr, i + 1, rest + 1, bound, s, _set);
            substr += ')';
        }
    }
    
    void dfsRhs(vector<string>& _cnt, string substr, int index, int rest, vector<int>& bound, string& s, unordered_set<string>& _set) {
        if ( rest == bound.size() ) {
            if ( bound.size() ) {
                for ( int i = index; i >= bound[bound.size() - 1]; -- i ) { substr += s[i]; }
            }
            for ( int i = 0, j = substr.size() - 1; i < j; ++ i, -- j ) { swap(substr[i], substr[j]); }
            if ( _set.find(substr) != _set.end() ) { return; }
            _set.insert(substr);
            _cnt.push_back(substr);
            return;
        }
        
        if ( index == bound[rest] ) { dfsRhs(_cnt, substr, index - 1, rest + 1, bound, s, _set); }
        for ( int i = index; i > bound[rest]; -- i ) {
            while ( i > bound[rest] && s[i] != '(' ) { substr += s[i --]; }
            dfsRhs(_cnt, substr, i - 1, rest + 1, bound, s, _set);
            substr += '(';
        }
    }
};
