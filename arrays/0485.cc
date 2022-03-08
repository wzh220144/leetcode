class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int32_t res = 0;
        int32_t pre = -1;
        int32_t cur = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != pre) {
                pre = nums[i];
                cur = nums[i];
            } else {
                cur += nums[i];
            }
            res = res > cur ? res : cur;
        }
        return res;
    }
};