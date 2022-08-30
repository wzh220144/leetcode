class Solution {
public:
    int rob(vector<int>& nums) {
        int32_t res = 0;
        if (nums.size() == 0) {
            return res;
        }
        std::vector<int32_t> dp;
        dp.resize(nums.size());
        for (int32_t i = 0; i < nums.size(); ++i) {
            dp[i] = nums[i];
            for (int32_t j = 0; j <= i - 2; ++j) {
                dp[i] = std::max(dp[j] + nums[i], dp[i]);
            }
            res = std::max(dp[i], res);
        }
        return res;
    }
};