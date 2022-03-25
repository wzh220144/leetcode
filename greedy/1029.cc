class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int32_t res = 0;
        vector<int32_t> ds;
        for (int32_t i = 0; i < costs.size(); ++i) {
            ds.emplace_back(costs[i][1] - costs[i][0]);
            res += costs[i][0];
        }
        sort(ds.begin(), ds.end(),  [](const int32_t a, const int32_t b) {
            return a < b;
        });
        int32_t t = ds.size() / 2;
        for (int32_t i = 0; i < t; ++i) {
            res += ds[i];
        }
        return res;
    }
};