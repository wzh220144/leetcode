class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int32_t i = nums.size() - 1;
    for(; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
    }
    int32_t left = i;
    int32_t right = nums.size() - 1;
    while(left < right) {
      int32_t t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      ++left;
      --right;
    }
    if (i > 0) {
      int32_t pre = i - 1;
      for (; i < nums.size(); ++i) {
        if (nums[pre] < nums[i]) {
          int32_t t = nums[pre];
          nums[pre] = nums[i];
          nums[i] = t;
          break;
        }
      }
    }
  }
};