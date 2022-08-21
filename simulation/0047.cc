class Solution {
public:
    void dfs(std::vector<std::vector<int32_t>>& res, vector<int32_t>& cur, const std::vector<int32_t> nums, std::set<int32_t> has) {
        if (cur.size() == nums.size()) {
            res.emplace_back(cur);
            return ;
        }
        int32_t pre = -1;
        for (int32_t i = 0; i < nums.size();++i) {
            int32_t t = nums[i];
            if (has.find(i) != has.end()) {
                continue;
            }
            if (pre == -1) {
                pre = i;
            } else if (nums[i] == nums[pre]) {
                continue;
            }
            pre = i;
            cur.emplace_back(t);
            has.insert(i);
            dfs(res, cur, nums, has);
            cur.pop_back();
            has.erase(i);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](const int32_t& x, const int32_t& y) {return x < y;});
        std::vector<std::vector<int32_t>> res;
        std::vector<int32_t> cur;
        std::set<int32_t> has;
        dfs(res, cur, nums, has);
        return res;
    }
};