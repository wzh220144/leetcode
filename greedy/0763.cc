class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int32_t> last_pos;
        for (int32_t i = 0; i < s.size(); ++i) {
            last_pos[s[i]] = i;
        }
        vector<int32_t> res;
        int32_t left = -1;
        int32_t right = -1;
        for (int32_t i = 0; i < s.size(); ++i) {
            if (left == -1) {
                left = i;
                right = last_pos[s[i]];
            } else {
                if (i <= right) {
                     right = max(right, last_pos[s[i]]);
                    
                } else {
                   res.emplace_back(right - left + 1);
                    left = i;
                    right = last_pos[s[i]];
                }
            }
        }
        if (left != -1) {
            res.emplace_back(right - left + 1);
        }
        return res;
    }
};