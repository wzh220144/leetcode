class Solution {
public:
    int32_t search_peak_index(vector<int>& nums) {
        int32_t high = nums.size() - 1;
        int32_t low = 0;
        if (nums[high] > nums[low]) {
            return high;
        }
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (nums[mid] >= nums[high]) {
                if ((mid == nums.size() - 1) || nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                low = mid + 1;
            } else {

                high = mid;
            }
        }
        return -1;
    }

    int32_t search_index(vector<int32_t>& nums, int32_t target, int32_t low, int32_t high) {
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int32_t peak_index = search_peak_index(nums);
        if (target > nums[peak_index]) {
            return -1;
        }
        int32_t res = search_index(nums, target, 0, peak_index);
        if (res >= 0) {
            return res;
        }
        return search_index(nums, target, peak_index + 1, nums.size() - 1);
    }
};