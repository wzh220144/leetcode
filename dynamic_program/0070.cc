class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int64_t p1 = 1;
        int64_t p2 = 2;
        int64_t res = 0;
        for (int i = 3; i <= n; ++i) {
            res = p1 + p2;
            p1 = p2;
            p2 = res;
        }
        return res;
    }
};