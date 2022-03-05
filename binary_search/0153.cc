class Solution {
public:
  int findMin(vector<int> &nums) {
    int32_t low = 0;
    int32_t high = nums.size() - 1;
    if (nums[low] < nums[high]) {
      return nums[low];
    }
    while (low <= high) {
      if (low == high) {
        return nums[low];
      }
      int32_t mid = low + ((high - low) >> 1);
      if (nums[low] > nums[mid]) {
        if (mid == 0 || nums[mid - 1] > nums[mid]) {
          return nums[mid];
        }
        high = mid - 1;
      } else {
        if (nums[mid + 1] < nums[mid]) {
          return nums[mid + 1];
        } else {
          low = mid + 1;
        }
      }
    }
    return nums[low];
  }
};
