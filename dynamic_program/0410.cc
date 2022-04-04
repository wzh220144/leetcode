class Solution {
public:
    void update(int32_t& x, int32_t t) {
        if (x == -1) {
            x = t;
        } else {
            x = x > t ? t : x;
        }
    }

    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<vector<int32_t>> dp;
        for (int32_t j = 0; j < nums.size(); ++j) {
            vector<int32_t> t;
            for (int32_t k = 0; k <= m; ++k) {
                t.emplace_back(-1);
            }
            dp.emplace_back(std::move(t));
        }
        
        vector<int32_t> sum;
        int32_t s = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            sum.emplace_back(s);
            s += nums[i];
        }
        sum.emplace_back(s);

        dp[0][1] = sum[1];

        for (int32_t i = 1; i < nums.size(); ++i) {
            dp[i][1] = sum[i + 1];
            for (int32_t j = 0; j < i; ++j) {
                for (int32_t k = 1; k < m; ++k) {
                    if (dp[j][k] == -1) {
                        break;
                    }
                    update(dp[i][k + 1], max(dp[j][k], sum[i + 1] - sum[j + 1]));
                }
            }
        }
        return dp[nums.size() - 1][m];
    }
};