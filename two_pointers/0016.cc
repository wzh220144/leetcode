class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        bool flag = false;
        int res = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            int32_t left = i + 1;
            int32_t right = nums.size() - 1;
            while (left < right) {
                int32_t t = nums[left] + nums[right];
                if (t + nums[i] == target) {
                    return target;
                } else if (t + nums[i] > target) {
                    --right;
                    if (flag) {
                        int32_t new_diff = abs(t + nums[i] - target);
                        int32_t old_diff = abs(res - target);
                        if (old_diff > new_diff) {
                            res = t + nums[i];
                        }
                    } else {
                        res = t + nums[i];
                    }
                    flag = true;
                } else if (t + nums[i] < target) {
                    ++left;
                    if (flag) {
                        int32_t new_diff = abs(t + nums[i] - target);
                        int32_t old_diff = abs(res - target);
                        if (old_diff > new_diff) {
                            res = t + nums[i];
                        }
                    } else {
                        res = t + nums[i];
                    }
                    flag = true;
                }
            }
        }
        return res;
    }
};