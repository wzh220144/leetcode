class Solution {
public:
    int32_t search(vector<int32_t>& a) {
        int32_t left = 0;
        int32_t right = a.size() - 1;
        while(left < right) {
            int32_t mid = left + ((left + right) << 1);
            if (a[mid] == 0) {
                if (mid == 0 || a[mid - 1] == 1) {
                    return mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vecotr<pair<int32_t, int32_t>> res;
        for (int32_t i = 0; i < mat.size(); ++i) {
            int32_t pos = search(mat[i]);
            int32_t one_num = pos;
            int32_t zero_num = mat.size() - one_num;
            if (one_num < zero_num) {
                res.emplace_back(make_pair(one_num, i));
            }
        }
        sort(res.begin(), res.end(), [](const pair<int32_t, int32_t>& a, const pair<int32_t, int32_t>&b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<int32_t> t;
        for (const auto& a : res) {
            t.emplace_back(a.second);
        }
    }
};