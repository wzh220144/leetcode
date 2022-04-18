class Solution {
public:
    int maxArea(vector<int>& height) {
        int32_t l = 0;
        int32_t r = height.size() - 1;
        int32_t res = 0;
        while (l < r) {
            int32_t t = height[l] > height[r] ? height[r] : height[l];
            res = max(res, (r - l) * t);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};