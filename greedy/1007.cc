class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int32_t, int32_t> top_cnt;
        unordered_map<int32_t, int32_t> bottom_cnt;
        unordered_map<int32_t, int32_t> val_cnt;
        int32_t rval = -1;
        for (int i = 0; i < tops.size(); ++i) {
            ++top_cnt[tops[i]];
            ++bottom_cnt[bottoms[i]];
            if (tops[i] != bottoms[i]) {
                ++val_cnt[tops[i]];
                ++val_cnt[bottoms[i]];
            } else {
                ++val_cnt[tops[i]];
            }
            if (i == tops.size() - 1) {
                if (val_cnt[tops[i]] == tops.size()) {
                    rval = tops[i];
                }
                if (val_cnt[bottoms[i]] == tops.size()) {
                    rval = bottoms[i];
                }
            }
        }
        if (rval == -1) {
            return -1;
        }
        return min(tops.size() - top_cnt[rval], tops.size() - bottom_cnt[rval]);
    }
};