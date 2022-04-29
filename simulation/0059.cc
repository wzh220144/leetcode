class Solution {
public:
    bool isValid(std::pair<int32_t, int32_t>& d, int32_t i, int32_t j, int32_t n, std::unordered_set<int32_t>& s) {
        i += d.first;
        j += d.second;
        if ((i >= 0) && (i < n) && (j >= 0) && (j < n) && (s.find(i * n + j) == s.end())) {
            return true;
        }
        return false;
    }

    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res;
        std::unordered_set<int32_t> s;
        for (int i = 0; i < n; ++i) {
            vector<int> t;
            for (int j = 0; j < n; ++j) {
                t.emplace_back(0);
            }
            res.emplace_back(std::move(t));
        }
        int32_t t = n * n;
        int32_t i = 0;
        int32_t j = 0;
        std::vector<std::pair<int32_t, int32_t>> dir = {
             {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        int d = 0;
        for (int k = 1; k <= t; ++k) {
            res[i][j] = k;
            s.insert(i * n + j);
            if (k == t) {
                break;
            }
            while (!isValid(dir[d], i, j, n, s)) {
                ++d;
                d = d % 4;
            }
            i += dir[d].first;
            j += dir[d].second;
        }
        return res;
    }
};