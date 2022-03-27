class Solution {
public:
  int32_t search(vector<int32_t> &a) {
    int32_t low = 0;
    int32_t high = a.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (a[mid] == 0) {
        if (mid == 0 || a[mid - 1] == 1) {
          return mid;
        }
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<std::pair<int32_t, int32_t>> res;
    for (int32_t i = 0; i < mat.size(); ++i) {
      int32_t pos = search(mat[i]);
      int32_t one_num = pos == -1 ? mat[i].size() : pos;
      int32_t zero_num = mat[i].size() - one_num;
      res.emplace_back(make_pair(one_num, i));
    }
    sort(res.begin(), res.end(),
         [](const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b) {
           if (a.first == b.first) {
             return a.second < b.second;
           }
           return a.first < b.first;
         });
    vector<int32_t> t;
    int32_t cnt = 0;
    for (const auto &a : res) {
      if (cnt == k) {
        break;
      }
      t.emplace_back(a.second);
      ++cnt;
    }
    return t;
  }
};