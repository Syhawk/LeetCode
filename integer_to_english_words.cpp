//uri:	https://leetcode.com/problems/integer-to-english-words/

/*
 *	将非负整数转换为字符串的形式，注意字符串中不应含有"and"。这样题目就简单了
 *	许多。可以直接列出所有可能出现的整数转换为字符串后的形式，然后直接拼接。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    void init() {
        s = "";
        flg = false;
    }
    
    void resolve(int value) {
        int h = value / hundred;
        int tmp = value % hundred;
        int t = tmp / 10;
        int u = tmp % 10;
        
        if(h) {
            if(flg) s += " ";
            s += unit[h] + " Hundred";
            flg = 1;
        }
        if(t >= 2) {
            if(flg) s += " ";
            s += decade[t - 2];
            flg = 1;
            if(u) s += " " + unit[u];
        }
        else if(t == 1) {
            if(flg) s += " ";
            s += tenSeveral[u];
            flg = 1;
        }
        else if(u != 0) {
            if(flg) s += " ";
            s += unit[u];
            flg = 1;
        }
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        init();
        
        int b = num / billion;
        if(b) {
            resolve(b);
            s += " Billion";
        }
        
        num = num % billion;
        int m = num / million;
        if(m) {
            resolve(m);
            s += " Million";
        }
        
        num = num % million;
        int t = num / thousand;
        if(t) {
            resolve(t);
            s += " Thousand";
        }
        num = num % thousand;
        if(num) {
            resolve(num);
        }
        
        return s;
    }

private:
    const int billion = 1000000000;
    const int million = 1000000;
    const int thousand = 1000;
    const int hundred = 100;
    const int ten = 10;
    const string unit[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string tenSeveral[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string decade[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string s;
    bool flg;
};
