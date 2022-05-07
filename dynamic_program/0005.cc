class Solution {
public:
  string longestPalindrome(string s) {
    std::vector<std::vector<int32_t>> dp;
    for (int32_t i = 0; i < s.size(); ++i) {
      std::vector<int32_t> t;
      dp.emplace_back(std::move(t));
      for (int32_t j = 0; j < s.size(); ++j) {
        dp[i].emplace_back(0);
      }
        dp[i][i] = 1;
    }
    int32_t len = 0;
    int32_t left = 0;
    int32_t right = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j >= 0; --j) {
        if (s[i] == s[j]) {
          if (i - j < 2) {
            dp[j][i] = 1;
          } else if (dp[j + 1][i - 1] == 1) {
            dp[j][i] = 1;
          }
        }
        if (dp[j][i] == 1) {
          if (i - j + 1 > len) {
            len = i - j + 1;
            left = j;
            right = i;
          }
        }
      }
    }
    return s.substr(left, len);
  }
};