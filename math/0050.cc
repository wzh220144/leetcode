class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        int64_t nn = static_cast<int64_t>(n);
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }
        if (nn == 1) {
            return x;
        }
        double t = myPow(x, nn / 2);
        if (nn % 2 == 1) {
            return t * t * x;
        } else {
            return t * t;
        }
    }
};