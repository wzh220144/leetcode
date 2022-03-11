class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int32_t cur = 0;
        for (int32_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }
        for(; cur < nums.size(); ++cur) {
            nums[cur] = 0;
        }
    }
};