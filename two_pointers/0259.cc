class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int32_t res = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            int32_t left = i + 1;
            int32_t right = nums.size() - 1;
            while (left < right) {
                int32_t t = nums[i] + nums[left] + nums[right];
                if (t == target) {
                    --right;
                } else if (t > target) {
                    --right;
                } else if (t < target) {
                    res += right - left;
                    ++left;
                }
            }
        }
        return res;
    }
};