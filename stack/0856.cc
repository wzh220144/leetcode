class Solution {
public:
    int scoreOfParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        stack<int32_t> st;
        st.push(0);
        for (const auto& x : s) {
            if (x == '(') {
                st.push(0);
            } else {
                int32_t v = st.top();
                st.pop();
                int32_t w = st.top();
                st.pop();
                st.push(w + (2 * v > 1 ? 2 * v : 1));
            }
        }
        return st.top();
    }
};