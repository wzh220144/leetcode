class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        int32_t len = nums.size();
        int32_t t = 1;
        for (int32_t i = 0; i < len; ++i) {
            t *= 2;
        }
        for (int i = 0; i < t; ++i) {
            int32_t tt = i;
            int32_t cur = 0;
            std::vector<int> t_res;
            while(tt > 0) {
                if (tt & 1) {
                    t_res.emplace_back(nums[cur]);
                }
                ++cur;
                tt /= 2;
            }
            res.emplace_back(std::move(t_res));
        }
        return res;
    }
};