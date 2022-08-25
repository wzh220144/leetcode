class Solution {
public:
  bool canCross(vector<int> &stones) {
    if (stones.size() <= 1) {
      return true;
    }
    int32_t next_diffs[3] = {-1, 0, 1};
    std::unordered_map<int32_t, std::unordered_set<int32_t>> m;
    m[0].insert(1);
    vector<bool> cans;
    cans.emplace_back(true);
    for (int32_t i = 1; i < stones.size(); ++i) {
      cans.emplace_back(false);
      for (int32_t j = 0; j < i; ++j) {
        const auto &s = m[j];
        int32_t diff = stones[i] - stones[j];
        if (s.find(diff) != s.end()) {
          cans[i] = true;
          for (const auto &x : next_diffs) {
            m[i].insert(x + diff);
          }
          break;
        }
      }
    }
    return cans[stones.size() - 1];
  }
};