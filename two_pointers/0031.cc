class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    if (nums.size() <= 1) {
      return;
    }
    int32_t i = nums.size() - 1;
    for (; i >= 1; --i) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
    }
    if (i > 0) {
      int32_t t = nums[i - 1];
      int32_t tt = i;
      for (int32_t j = i; j <= nums.size() - 1; ++j) {
        if (t >= nums[j]) {
          break;
        }
        tt = j;
      }
      nums[i - 1] = nums[tt];
      nums[tt] = t;
    }
    int32_t left = i;
    int32_t right = nums.size() - 1;
    while (left < right) {
      int32_t t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      ++left;
      --right;
    }
  }
};