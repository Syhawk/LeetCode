//uri:	https://leetcode.com/problems/majority-element-ii/

/*
 *	由于题目要求是O(1)空间复杂度，线性时间，所以，可以采用三个下标，分别表示三个不同元素的下标，找到之后，就与i, i + 1, i + 2所表示的元素
 *	进行交换，然后第一个下标跳过i + 2，从i + 3处继续寻找三个不同的元素，直到找不到为止。然后判断i， j下标所表示的元素是否符合条件即可。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int len = nums.size();
        for(int i = 0, j = i + 1, k = j + 1; i < len; i += 3) {
            for(j = max(i + 1, j); j < len && nums[j] == nums[i]; ++ j);
            for(k = max(j + 1, k); k < len && (nums[k] == nums[i] || nums[k] == nums[j]); ++ k);
            
            if(k < len) {
                swap(nums[i + 1], nums[j ++]);
                swap(nums[i + 2], nums[k ++]);
                continue;
            }
            if(j < len && majority(nums[j], nums, len)) { v.push_back(nums[j]); }
            if(majority(nums[i], nums, len)) { v.push_back(nums[i]); }
            i = len;
        }
        
        return v;
    }
    
    bool majority(int val, vector<int>& nums, int len) {
        int cnt = 0;
        for(int i = 0; i < len; ++ i) {
            if(nums[i] == val) { cnt += 1; }
        }
        
        return (cnt > len / 3);
    }
};

/*
 *	用两个变量分别表示两个不同的元素，再用另外两个变量表示这两个元素出现的次数，遇到的元素值如果是这两个元素中的一个，那么该元素次数增加1，
 *	否则这两个元素均减1。如果两个变量有空缺，即出现的次数为0，那么就用新的元素替代。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = 2;
        int len = nums.size();
        vector<int> a(N, 0);
        vector<int> cnt(N, 0);

        for (int i = 0; i < len; ++ i) {
            int w = -1;
            for (int k = 0; k < N; ++ k) {
                if (a[k] == nums[i]) {
                    w = k;
                    break;
                }
            }
            
            if (w != -1) {
                ++ cnt[w];
                continue;
            }
                
            for (int k = 0; k < N; ++ k) {
                if (cnt[k] == 0){
                    w = k;
                    cnt[k] = 1;
                    a[k] = nums[i];
                    break;
                }
            }
            
            if(w != -1) { continue; }
            for (int k = 0; k < N; ++ k) { cnt[k] -= 1; }
        }
          
        vector<int> v;
        for (int i = 0; i < N; ++ i) {
          if(cnt[i] < 1) { continue; }
          int sum = 0;
          for (int j = 0; j < len; ++ j) {
              if (nums[j] == a[i]) { sum += 1; }
          }
          
          if (sum > len / 3) { v.push_back(a[i]); }
        }
        
        return v;
    }
};
