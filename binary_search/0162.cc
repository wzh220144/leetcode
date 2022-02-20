class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int32_t low = 0;
        int32_t high = nums.size() - 1;
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (low == high) {
                return low;
            }
            if (mid == 0) {
                if (nums[mid] < nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else if (mid == nums.size() - 1) {
                if (nums[mid] < nums[mid - 1]) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            } else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid] > nums[mid + 1] && nums[mid - 1] > nums[mid] ) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};