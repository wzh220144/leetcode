class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word1.size() == 0) {
      return word2.size();
    }
    if (word2.size() == 0) {
      return word1.size();
    }
    std::vector<std::vector<int32_t>> dp;
    dp.resize(word1.size() + 1);
    for (auto &x : dp) {
      x.resize(word2.size() + 1);
    }
    for (int32_t i = 0; i <= word1.size(); ++i) {
      dp[i][0] = i;
    }
    for (int32_t i = 0; i <= word2.size(); ++i) {
      dp[0][i] = i;
    }
    for (int32_t i = 1; i <= word1.size(); ++i) {
      for (int32_t j = 1; j <= word2.size(); ++j) {
        dp[i][j] = std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = std::min(dp[i - 1][j - 1], dp[i][j]);
        } else {
          dp[i][j] = std::min(dp[i - 1][j - 1] + 1, dp[i][j]);
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }
};