class Solution {
public:
    int32_t mmax(int32_t a, int32_t b) {
        return a > b ? a : b;
    }

    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int32_t, int32_t>> s;
        int32_t res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            auto height = heights[i];
            int32_t cur = i;
            while(!s.empty()) {
                auto& top = s.top();
                if (top.first >= height) {
                    res = mmax(res, (i - top.second) * top.first);
                    cur = top.second;
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(std::make_pair(height, cur));
        }
        while(!s.empty()) {
            auto& top = s.top();
            res = mmax(res, (heights.size() - top.second) * top.first);
            s.pop();
        }
        return res;
    }
};