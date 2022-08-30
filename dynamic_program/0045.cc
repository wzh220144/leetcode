class Solution {
public:
  int jump(vector<int> &nums) {
    std::vector<int32_t> dp;
    dp.resize(nums.size());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (i != 0 && dp[i] == 0) {
        continue;
      }
      for (int32_t j = 1; j <= nums[i]; ++j) {
        int32_t next = i + j;
        if (next >= nums.size()) {
          break;
        }
        if (dp[next] == 0) {
          dp[next] = dp[i] + 1;
        } else {
          dp[next] = std::min(dp[i] + 1, dp[next]);
        }
      }
    }
    return dp[nums.size() - 1];
  }
};