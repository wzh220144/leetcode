class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    std::vector<std::vector<int32_t>> dp;
    int32_t res = 0;
    for (int32_t i = 0; i < matrix.size(); ++i) {
      auto cur = matrix[i];
      auto size = matrix[i].size();
      std::vector<int32_t> cur_dp;
      dp.emplace_back(std::move(cur_dp));
      int32_t cur_max = 0;
      for (int32_t j = 0; j < size; ++j) {
        if (cur[j] == '1') {
          ++cur_max;
          if ((i > 0) && (j > 0)) {
            int32_t t = min(dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            t = min(t, cur_max);
            res = max(t * t, res);
            dp[i].emplace_back(t);
          } else {
            res = max(res, 1);
            dp[i].emplace_back(1);
          }
        } else {
          cur_max = 0;
          dp[i].emplace_back(0);
        }
      }
    }
    return res;
  }
};