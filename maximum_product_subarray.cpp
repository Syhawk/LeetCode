//uri:	https://leetcode.com/problems/maximum-product-subarray/

/*
 *	对于0需要特判，对于负数，每次取偶数个负数。
 *	空间复杂度：O(1).
 *	时间复杂度：O(n).
 * */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        long long result = nums[0];
        long long tmp = 1;
        int cnt = 0;
        int pre = 0;
        int p = 0;
        for(int i = 0; i < len; ++ i) {
            if(nums[i]) {
                tmp *= nums[i];
                if(nums[i] < 0)
                    cnt += 1;
                p += 1;
            }
            if(i == len - 1 || nums[i] == 0) {
                if(nums[i] == 0) result = max(result, 0LL);
                if(p) result = max(result, tmp);
                if(cnt % 2 == 1) {
                    long long c = tmp;
                    for(int j = i; j > pre; -- j) {
                        if(nums[j] == 0) continue;
                        c /= nums[j];
                        if(nums[j] < 0) {
                            result = max(result, c);
                            break;
                        }
                    }
                    for(int j = pre; j < i; ++ j) {
                        -- p;
                        if(nums[j] == 0) continue;
                        tmp /= nums[j];
                        if(nums[j] < 0) {
                            if(p) result = max(result, tmp);
                            break;
                        }
                    }
                }
                pre = i + 1;
                cnt = 0;
                tmp = 1;
                p = 0;
            }
            
        }
        
        return result;
    }
};
