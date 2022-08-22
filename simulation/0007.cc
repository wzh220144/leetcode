class Solution {
public:
    int reverse(int x) {
        int32_t res = 0;
        int32_t max_pre = INT_MAX / 10;
        int32_t max_left = INT_MAX % 10;
        int32_t min_pre = INT_MIN / 10;
        int32_t min_left = INT_MIN % 10;
        while(x != 0) {
            int32_t m = x % 10;
            x /= 10;
            if ( (res > max_pre) || ( (res == max_pre) && (m > max_left) ) ) {
                return 0;
            }
            if ( (res < min_pre) || ( (res == min_pre) && (m < min_left) ) ) {
                return 0;
            }
            res = res * 10 + m;
        }
        return res;
    }
};