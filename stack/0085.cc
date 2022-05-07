class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int32_t res = 0;
    vector<int32_t> pre;
    for (int32_t i = 0; i < matrix.size(); ++i) {
      auto &cur = matrix[i];
      for (int32_t j = 0; j < cur.size(); ++j) {
        int32_t t = cur[j] - '0';
        if (i == 0) {
          pre.emplace_back(t);
        } else {
          if (t == 0) {
            pre[j] = 0;
          } else {
            ++pre[j];
          }
        }
      }

      std::stack<std::pair<int32_t, int32_t>> s;
      for (int32_t j = 0; j < pre.size(); ++j) {
        int32_t t = j;
        while (!s.empty()) {
          auto &top = s.top();
          if (top.first < pre[j]) {
            break;
          } else {
            res = max(res, (j - top.second) * top.first);
            t = top.second;
            s.pop();
          }
        }
        if (pre[j] > 0) {
          s.push(std::make_pair(pre[j], t));
        }
      }
      while (!s.empty()) {
        auto &top = s.top();
        int32_t t = (pre.size() - top.second) * top.first;
        res = max(res, t);
        s.pop();
      }
    }
    return res;
  }
};