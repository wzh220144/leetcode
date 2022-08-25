class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<std::pair<int32_t, int32_t>> s;
        int32_t res = 0;
        for (int32_t i = 0; i < height.size(); ++i) {
            int32_t h = height[i];
            if (h == 0) {
                continue;
            }
            int32_t pre = 0;
            while(!s.empty()) {
                auto top = s.top();
                if (top.second > h) {
                    res += (i - top.first - 1) * (h - pre);
                    break;
                } else {
                    s.pop();
                    res += (top.second - pre) * (i - top.first - 1);
                    pre = top.second;
                }
            }
            s.push(std::make_pair(i, h));
        }
        return res;
    }
};