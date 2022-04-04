class Solution {
public:
    void reverseString(vector<char>& s) {
        int32_t l = 0;
        int32_t r = s.size() - 1;
        while(l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            ++l;
            --r;
        }
    }
};