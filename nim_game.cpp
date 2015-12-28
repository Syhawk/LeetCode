//uri:	https://leetcode.com/problems/nim-game/

/*
 *	博弈题目。有一堆石子，两个人每次从这堆石子取1-3个石子，谁取到最后一个谁就
 *	获胜，先手为自己。
 *	事实上就是每次取石子时保证两个人取石子的个数之和为4。
 *	空间复杂度：O(1).
 *	时间复杂度：O(1).
 * */

class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0) return false;
        return true;
    }
};
