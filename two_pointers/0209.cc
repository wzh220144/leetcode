#include <queue>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int32_t sum = 0;
        int32_t res = -1;
        std::queue<int32_t> q;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            q.push(nums[i]);
            while(!q.empty()) {
                if (sum >= target) {
                    if (res == -1) {
                        res = q.size();
                    } else {
                        res = res > q.size() ? q.size() : res;
                    }
                    sum -= q.front();
                    q.pop();
                } else {
                    break;
                }
            }
        }
        if (res == -1) {
            res = 0;
        }
        return res;
    }
};