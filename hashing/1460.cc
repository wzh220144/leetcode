class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::unordered_map<int32_t, int32_t> m;
        for (const auto& x : target) {
            ++m[x];
        }
        bool flag = true;
        for (const auto& x : arr) {
            --m[x];
            if (m[x] < 0) {
                flag = false;
            }
        }
        return flag;
    }
};