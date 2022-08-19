/**
 * @brief 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        if (n == 0) {
            res.emplace_back("");
            return res;
        }
        for (int32_t i = 0; i < n; ++i) {
            for (const auto& x : generateParenthesis(i)) {
                for (const auto& y : generateParenthesis(n - i - 1)) {
                    res.emplace_back(x + "(" + y + ")");
                }
            }
        }
        return res;
    }
};