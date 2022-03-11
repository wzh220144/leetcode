class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int32_t res = 0;
        std::map<int32_t, int32_t> s;
        int32_t sum = 0;
        for (const auto& x : nums) {
            sum += x;
            if (sum == k) {
                ++res;
            }
            int32_t t = sum - k;
            if (s.find(t) != s.end()) {
                res += s[t];
            }
            s[sum] += 1;
        }
        return res;
    }
};