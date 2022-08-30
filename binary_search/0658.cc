class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int32_t right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int32_t left = right - 1;
        while(k--) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else {
                int32_t tr = abs(arr[right] - x);
                int32_t tl = abs(x - arr[left]);
                if (tr >= tl) {
                    --left;
                } else {
                    ++right;
                }
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
