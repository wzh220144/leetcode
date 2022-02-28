class Solution {
public:
  int32_t search_index(vector<vector<int32_t>> &matrix, int32_t target) {
    int32_t low = 0;
    int32_t high = matrix.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (matrix[mid][0] == target) {
        return mid;
      } else if (matrix[mid] < target) {
        if (mid == (matrix.size() - 1) || matrix[mid + 1] > target) {
          return mid;
        }
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }

  bool search(vector<int32_t> &nums, int32_t target) {
    int32_t low = 0;
    int32_t high = matrix.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int32_t index = search_index(matrix, target);
    if (index < 0) {
      return false;
    }
    return search(matrix[index], target);
  }
};