class Solution {
public:

    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        if (n == 0) {
            res.emplace_back("");
            return res;
        }
        for (int i = 0; i < n; ++i) {
            for (const auto& x : generateParenthesis(i)) {
                for (const auto& y : generateParenthesis(n - i - 1)) {
                    res.emplace_back(x + "(" + y + ")");
                }
            }
        }
        return res;
    }
};