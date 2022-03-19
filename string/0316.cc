class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int32_t> mt;
    set<char> st;

    for (int32_t i = 0; i < s.size(); ++i) {
      mt[s[i]] = i;
    }

    stack<char> r;
    for (int32_t i = 0; i < s.size(); ++i) {
      char cur = s[i];
      if (st.find(cur) != st.end()) {
        continue;
      }
      while (!r.empty()) {
        char t = r.top();
        if (cur < t) {
          if (mt.find(t) != mt.end()) {
            if (mt[t] > i) {
              st.erase(t);
              r.pop();
            } else {
              break;
            }
          } else {
            break;
          }
        } else {
          break;
        }
      }
      r.push(cur);
      st.insert(cur);
    }
    string res = "";
    while (!r.empty()) {
      res += r.top();
      r.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};