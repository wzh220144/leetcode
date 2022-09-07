class Solution {
public:
  string countAndSay(int n) {
    std::string res = "1";
    int32_t cnt = 1;
    while (cnt < n) {
      std::string next = "";
      char pre = '\0';
      int32_t c = 0;
      for (const auto x : res) {
        if (x == pre) {
          ++c;
        } else {
          if (pre != '\0') {
            next += std::to_string(c) + pre;
          }
          pre = x;
          c = 1;
        }
      }
      if (c != 0) {
        next += std::to_string(c) + pre;
      }
      res = next;
      ++cnt;
    }
    return res;
  }
};