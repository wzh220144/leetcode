class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int32_t low = 0;
    int32_t high = nums.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (nums[mid] < target) {
        if (mid == nums.size() - 1 || nums[mid + 1] >= target) {
          return mid + 1;
        }
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return 0;
  }
};
