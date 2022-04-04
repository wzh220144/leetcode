class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() <= 2) {
            return true;
        }
        int32_t l = s.size();
        int32_t mid = l / 2;
        bool same = true;
        for(int32_t i = 0; i < mid; ++i) {
            if (s[i] != s[l - 1 - i]) {
                same = false;
                break;
            }
        }
        if (same) {
            return true;
        }
        mid = (l - 1) / 2;
        int32_t right = l - 1;
        int32_t cnt = 0;
        same = true;
        int32_t i = 0;
        for (; i < mid;) {
            if (s[i] != s[right]) {
                if (cnt > 0) {
                    same = false;
                    break;
                }
                ++cnt;
            } else {
                ++i;
            }
            --right;
        }
        if (same && i == mid) {
            return true;
        }
        int32_t left = 0;
        cnt = 0;
        same = true;
        i = 0;
        for(; i < mid;) {
            if (s[left] != s[l - i - 1]) {
                if (cnt > 0) {
                    same = false;
                    break;
                }
                ++cnt;
            } else {
                ++i;
            }
            ++left;
        }
        return same && i == mid;
    }
};