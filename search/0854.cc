class Solution {
  unordered_map<string, int> um;
  int dfs(string s1, string s2, int idx) {
    if (s1 == s2)
      return 0;
    if (um.count(s1))
      return um[s1];
    int val = INT_MAX;
    for (int i = idx; i < s1.size(); i++) {
      if (s1[i] == s2[i])
        continue;

      char c1 = s1[i];
      char c2 = s2[i];
      int j;
      for (j = i + 1; j < s1.size(); j++) {
        string t = s1;
        if (t[j] == c2 && s2[j] != c2) {
          swap(t[i], t[j]);
          val = min(val, 1 + dfs(t, s2, i + 1));
        }
      }
      return um[s1] = val;
    }
    return 0;
  }

public:
  int kSimilarity(string s1, string s2) {
    int idx = 0;
    return dfs(s1, s2, 0);
  }
};