class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::map<int32_t, int32_t> m;
    for (int32_t i = 0; i < nums.size(); ++i) {
      int32_t other = target - nums[i];
      if (m.find(other) != m.end()) {
        return {m[other], i};
      } else {
        m[nums[i]] = i;
      }
    }
    return {-1, -1};
  }
};