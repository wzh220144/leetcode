class Solution {
public:
    int32_t search_low(vector<int32_t>& nums, int32_t target) {
        int32_t low = 0;
        int32_t high = nums.size() - 1;
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] == target) {
                if ( (mid == 0) || nums[mid - 1] < target) {
                    return mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    int32_t search_high(vector<int32_t>& nums, int32_t target) {
        int32_t low = 0;
        int32_t high = nums.size() - 1;
        while(low <= high) {
            int32_t mid = low + ((high - low) >> 1);
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] == target) {
                if ( (mid == (nums.size() - 1)) || nums[mid + 1] > target) {
                    return mid;
                }
                low = mid + 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int32_t> res;
        res.emplace_back(search_low(nums, target));
        res.emplace_back(search_high(nums, target));
        return res;
    }
};