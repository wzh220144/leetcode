class Solution {
public:
    int32_t isEven(int32_t x) {
        int32_t res = 1;
        x /= 10;
        while(x > 0) {
            x = x / 10;
            ++res;
        }
        if (res % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int findNumbers(vector<int>& nums) {
        int32_t res = 0;
        for (const auto& x : nums) {
            res += isEven(x);
        }
        return res;
    }
};