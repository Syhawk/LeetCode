//uri:	https://leetcode.com/problems/add-digits/

/*
 *	每次都是各个位的数字相加，就是相当于把十进制数字改为9进制数字
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        int back = num % 9;

        return back == 0 ? 9 : back;
    }
};
