class Solution {
public:
  int compress(vector<char> &chars) {
    int32_t res = 0;
    char pre = '\0';
    int32_t cnt = 0;
    int32_t pre_pos = 0;
    for (int i = 0; i < chars.size(); ++i) {
      if (pre == chars[i]) {
        ++cnt;
      } else {
        if (pre != '\0') {
          if (cnt == 1) {
            chars[pre_pos++] = pre;
            res += 1;
          } else if (cnt > 1) {
            chars[pre_pos++] = pre;
            ++res;
            for (const auto& x : std::to_string(cnt)) {
              chars[pre_pos++] = x;
              ++res;
            }
          }
        }
        pre = chars[i];
        cnt = 1;
      }
    }
    if (cnt == 1) {
      chars[pre_pos++] = pre;
      res += 1;
    } else if (cnt > 1) {
      chars[pre_pos++] = pre;
      ++res;
      for (const auto& x : std::to_string(cnt)) {
        chars[pre_pos++] = x;
        ++res;
      }
    }
    return res;
  }
};