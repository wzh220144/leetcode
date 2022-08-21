class Solution {
public:
    void dfs(std::vector<std::vector<int32_t>>& res, vector<int32_t>& cur, const std::vector<int32_t> nums, std::set<int32_t> has) {
        if (cur.size() == nums.size()) {
            res.emplace_back(cur);
            return ;
        }
        for (int32_t i = 0; i < nums.size(); ++i) {
            int32_t t = nums[i];
            if (has.find(t) != has.end()) {
                continue;
            }
            cur.emplace_back(t);
            has.insert(t);
            dfs(res, cur, nums, has);
            cur.pop_back();
            has.erase(t);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int32_t>> res;
        std::vector<int32_t> cur;
        std::set<int32_t> has;
        dfs(res, cur, nums, has);
        return res;
    }
};