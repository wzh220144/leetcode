class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::set<char> m;
    std::queue<char> q;
    int32_t res = 0;
    for (int32_t i = 0; i < s.size(); ++i) {
      while (m.find(s[i]) != m.end()) {
        char t = q.front();
        m.erase(m.find(m));
      }
      m.insert(s[i]);
      res = res > m.size() ? res : m.size();
    }
    return res;
  }
};