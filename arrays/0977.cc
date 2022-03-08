class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int32_t> res;
        stack<int32_t> q;
        int32_t left = 0;
        int32_t right = nums.size() - 1;
        while(left <= right) {
            if (left == right) {
                q.push(nums[left] * nums[left]);
                ++left;
                --right;
            } else if (abs(nums[left]) == abs(nums[right])) {
                q.push(nums[left] * nums[left]);
                q.push(nums[right] * nums[right]);
                ++left;
                --right;
            } else if (abs(nums[left]) > abs(nums[right])) {
                q.push(nums[left] * nums[left]);
                ++left;
            } else {
                q.push(nums[right] * nums[right]);
                --right;
            }
        }
        while(!q.empty()) {
            res.emplace_back(q.top());
            q.pop();
        }
        return res;
    }
};