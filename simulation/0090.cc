class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::vector<std::vector<int>> res;
    int32_t len = nums.size();
    int32_t t = 1;
    for (int32_t i = 0; i < len; ++i) {
      t *= 2;
    }
    std::sort(nums.begin(), nums.end());
    std::unordered_set<std::string> s;
    for (int i = 0; i < t; ++i) {
      int32_t tt = i;
      int32_t cur = 0;
      std::vector<int> t_res;
      std::string t_str = "";
      while (tt > 0) {
        if (tt & 1) {
          t_res.emplace_back(nums[cur]);
          t_str += std::to_string(nums[cur]) + "_"; 
        }
        ++cur;
        tt /= 2;
      }
      if (s.find(t_str) == s.end()) {
        res.emplace_back(std::move(t_res));
        s.insert(t_str);
      }
    }
    return res;
  }
};