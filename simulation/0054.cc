class Solution {
public:
    const int32_t xs[] = {1, 0, -1, 0};
    const int32_t ys[] = {0, 1, 0, -1};

    bool IsValid(const int32_t x, const int32_t y, const int32_t n, const int32_t m) {
        if (x >= 0 && y >= 0 && x < n && y < m) {
            return true;
        }
        return false;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int32_t> res;
        if (matrix.size() == 0) {
            return res;
        }
        int32_t m = matrix.size();
        int32_t n = matrix[0].size();
        int32_t travel_m = 1;
        int32_t direction = 0;
        int32_t x = 0;
        int32_t y = 0;
        std::set<int32_t> s;
        while(true) {
            res.emplace(matrix[x][y]);
            s.insert(x + y * n);
            int32_t key = next_x + next_y * n;
            bool valid = false;
            for (int32_t i = 0; i < 4; ++i) {
                int32_t next_x = x + xs[direction];
                int32_t next_y = y + ys[direction];
                if (IsValid(next_x, next_y, n, m) && s.find(key) == s.end()) {
                    x = next_x;
                    y = next_y;
                    valid = true;
                    break;
                }
                ++direction;
                direction = direction % 4;
            }
        }
        return res;
    }
};