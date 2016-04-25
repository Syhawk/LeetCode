//uri:	https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
 *	采用栈来存储当前的值以及对应的最小下标。栈内存储的值对以值作为基点递增有序。
 *	步骤：（1）如果遇到的元素值小于等于栈内的最大值，那么栈删除该元素值，但是要记录下该元素值对应的下标。
 *		上述步骤在循环中随时记录所出现的最大矩形面积。步骤（1）直至遇到的元素值<=当前元素值或者栈为空时结束，并进入步骤（2）。
 *		（2）把当前值和记录的最小的下标作为值对放入栈中。
 *	处理剩下的栈内的递增值对，记录最大矩形面积。
 *	
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int MAX = 0;
        int len = heights.size();
        
        for ( int i = 0; i < len; ++ i) {
            while ( i < len && (st.empty() || st.top().first < heights[i]) ) {
                st.push(make_pair(heights[i], i));
                ++ i;
            }
            
            if ( i >= len ) { break; }
            int index = i;
            while ( !st.empty() && st.top().first >= heights[i] ) {
                MAX = max(MAX, st.top().first);
                MAX = max(MAX, heights[i] * (i - st.top().second + 1));
                MAX = max(MAX, st.top().first * (i - st.top().second));
                index = st.top().second;
                st.pop();
            }
            
            st.push(make_pair(heights[i], index));
        }
        
        while ( !st.empty() ) {
            MAX = max(MAX,  st.top().first * (len - st.top().second));
            st.pop();
        }
        
        return MAX;
    }
};
