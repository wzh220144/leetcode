class Solution {
public:
  int search(vector<int> &nums, int target) {
    int32_t low = 0;
    int32_t high = nums.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }
};