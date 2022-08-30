class Solution {
public:
  bool valid(const std::string &s) {
    if (s.size() == 1) {
      return true;
    } else {
      if (s[0] == '0') {
        return false;
      }
      int32_t t = std::atoi(s.c_str());
      if (t < 256) {
        return true;
      } else {
        return false;
      }
    }
    return false;
  }

  void dfs(std::vector<int32_t> &splits, const std::string &s,
           std::vector<std::string> &res) {
    if (splits.size() == 3) {
      int32_t size = s.size() - splits[2];
      if (size > 0 && size < 4) {
        if (valid(s.substr(splits[2], s.size()))) {
          std::string sub_res = s.substr(0, splits[0]) + "." +
                                s.substr(splits[0], splits[1] - splits[0]) + "." +
                                s.substr(splits[1], splits[2] - splits[1]) + "." +
                                s.substr(splits[2], s.size() - splits[2]);
          res.emplace_back(std::move(sub_res));
        }
      }
      return;
    }
    int32_t cur_start = 0;
    if (splits.size() > 0) {
      cur_start = splits[splits.size() - 1];
    }
    for (int32_t i = 1; i < 4; ++i) {
      if (cur_start + i < s.size() && valid(s.substr(cur_start, i))) {
        splits.emplace_back(cur_start + i);
        dfs(splits, s, res);
        splits.pop_back();
      }
    }
    return;
  }

  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> res;
    std::vector<int32_t> splits;
    dfs(splits, s, res);
    return res;
  }
};