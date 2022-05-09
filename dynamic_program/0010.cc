class Solution {
public:
  bool isMatch(string s, string p) {
    std::string pt = "";
    std::vector<int32_t> p_type(p.size());
    for (int i = 0; i < p.size();) {
      pt += p[i];
      if (i + 1 < p.size() && p[i + 1] == '*') {
        p_type[pt.size() - 1] = 1;
        i += 2;
      } else {
        p_type[pt.size() - 1] = 0;
        i += 1;
      }
    }
    std::vector<std::vector<bool>> dp(2);
    dp[0].resize(s.size() + 1);
    dp[1].resize(s.size() + 1);
    int32_t cur = 0;
    int32_t pre = 1;
    dp[pre][0] = true;
    for (int32_t i = 0; i < pt.size(); ++i) {
      for (int32_t j = 1; j <= s.size(); ++j) {
        if (p_type[i] == 1) {
          if (dp[pre][j - 1]) {
            dp[cur][j - 1] = true;
          }
          if (dp[pre][j]) {
              dp[cur][j] = dp[pre][j];
          }
          if (dp[cur][j - 1] && ((pt[i] == '.') || (pt[i] == s[j - 1])) )  {
            dp[cur][j] = true;
          }
        } else if (dp[pre][j - 1] && ((pt[i] == '.') || (pt[i] == s[j - 1])) ) {
          dp[cur][j] = true;
        }
      }
      pre = 1 - pre;
      cur = 1 - cur;
      for (int32_t j = 0; j <= s.size(); ++j) {
        dp[cur][j] = false;
      }
    }
    return dp[pre][s.size()];
  }
};