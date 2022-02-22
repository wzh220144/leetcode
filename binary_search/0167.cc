class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int32_t low = 0;
        int32_t high = numbers.size() - 1;
        while(low < high) {
            int32_t sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum > target) {
                --high;
            } else {
                ++low;
            }
        }
        return {-1, -1};
    }
};