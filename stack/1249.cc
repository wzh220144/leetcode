class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int32_t> st;
        std::set<int32_t> ss;
        for (int32_t i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (st.empty()) {
                    ss.insert(i);
                } else {
                    st.pop();
                }
            } else if (s[i] == '(') {
                st.push(i);
            }
        }
        while(!st.empty()) {
            ss.insert(st.top());
            st.pop();
        }
        string res = "";
        for (int32_t i = 0; i < s.size(); ++i) {
            if (ss.find(i) != ss.end()) {
                continue;
            }
            res += s[i];
        }
        return res;
    }
};