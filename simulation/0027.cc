class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int32_t index = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                continue;
            }
            nums[index++] = nums[i];
        }
        return index;
    }
};