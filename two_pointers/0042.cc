class Solution {
public:
    int trap(vector<int>& height) {
        int32_t res = 0;
        std::stack<std::pair<int32_t, int32_t>> s;
        for (int32_t i = 0; i < height.size(); ++i) {
            int32_t h = height[i];
            if (h == 0) {   //0没用
                continue;
            }
            int32_t pre = 0;
            while(!s.empty()) {
                auto& t = s.top();
                if (t.first > h) {
                    res += (i - t.second - 1) * (h - pre);
                    break;
                } else {
                    res += (t.first - pre) * (i - t.second - 1);
                    pre = t.first;
                    s.pop();
                }
            }
            s.push(make_pair(h, i));
        }
        return res;
    }
};