class Solution {
public:
    void dfs(vector<int>& nums, const int32_t& key) {
        int32_t cur = nums[key];
        if (cur == key + 1) {
            return;
        }
        if (cur <= 0) {
            return ;
        }
        if (cur > nums.size()) {
            nums[key] = -1;
            return;
        }
        // 置换nums[key], nums[cur - 1]
        int32_t t = nums[cur - 1];
        if (t == cur) {
            nums[key] = -1;
            return;
        }
        nums[cur - 1] = cur;
        nums[key] = t;
        dfs(nums, key);
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int32_t i = 0; i < nums.size(); ++i) {
            dfs(nums, i);
        }
        int32_t res = nums.size() + 1;
        for (int32_t i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                res = i + 1;
                break;
            }
        }
        return res;
    }
};