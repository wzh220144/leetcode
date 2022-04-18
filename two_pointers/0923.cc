class Solution {
public:
  int threeSumMulti(vector<int> &arr, int target) {
    int32_t mod = 1000000007;
    int32_t res = 0;
    sort(arr.begin(), arr.end());
    for (int32_t i = 0; i < arr.size(); ++i) {
      int32_t new_target = target - arr[i];
      int32_t left = i + 1;
      int32_t right = arr.size() - 1;
      while (left < right) {
        int32_t t = arr[left] + arr[right];
        if (t < new_target) {
          ++left;
        } else if (t > new_target) {
          --right;
        } else if (arr[left] != arr[right]) {
          int32_t tt = arr[left];
          int32_t left_cnt = 0;
          while (arr[left] == tt) {
            ++left;
            ++left_cnt;
          }
          tt = arr[right];
          int32_t right_cnt = 0;
          while (arr[right] == tt) {
            --right;
            ++right_cnt;
          }
          res = (res + right_cnt * left_cnt) % mod;
        } else {
          int32_t l = right - left + 1;
          res = (res + l * (l - 1) / 2) % mod;
          break;
        }
      }
    }
    return res;
  }
};