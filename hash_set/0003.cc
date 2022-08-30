class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int32_t> dp;
        dp.resize(nums.size());
        int32_t res;
        for (const auto& x : nums) {
            ++dp[x];
            if (dp[x] > 1) {
                res = x;
                break;
            }
        }
        return res;
    }
};