class Solution {
public:
  int numDistinct(string s, string t) {
    std::vector<std::vector<int32_t>> dp;
    dp.resize(word1.size() + 1);
    for (auto &x : dp) {
      x.resize(word2.size() + 1);
    }

    for (int32_t i = 1; i <= word1.size(); ++i) {
      for (int32_t j = 1; j <= word2.size(); ++j) {

        

      }
    }
  }
};