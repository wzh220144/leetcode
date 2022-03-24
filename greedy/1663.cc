class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 0);
        for (int32_t i = 0; i < n; ++i) {
            int32_t left = n - i - 1;
            int32_t cur = k - left;
            if (cur > 26) {
                res[n - i - 1] = 'z';
                k -= 26;
            } else {
                res[n - i - 1] = static_cast<char>('a' + cur - 1);
                k -= cur;
            }
        }
        return res;
    }
};