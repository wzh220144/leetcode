class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::vector<std::vector<char>> rows;
        for (int i = 0; i < numRows; ++i) {
            std::vector<char> t;
            rows.emplace_back(std::move(t));
        }
        int32_t row = 0;
        int32_t col = 0;
        for (int i = 0; i < s.size(); ++i) {
            while(rows[row].size() < col) {
                rows[row].emplace_back('\0');
            }
            rows[row].emplace_back(s[i]);
            if (col % (numRows - 1) == 0 ) {
                if (row + 1 < numRows) {
                    ++row;
                } else {
                    --row;
                    ++col;
                }
            } else {
                --row;
                ++col;
            }
        }
        std::string res;
        for (int i = 0; i < numRows; ++i) {
            for (auto x : rows[i]) {
                if (x != '\0') {
                    res += x;
                }
            }
        }
        return res;
    }
};