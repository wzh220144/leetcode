class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int32_t res = 0;
        int32_t pre = 0;
        for (int32_t i = 2; i < nums.size(); ++i) {
            int32_t cur = 0;
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
                ++cur;
                cur += pre;
            }
            res += cur;
            pre = cur;
        }
        return res;
    }
};