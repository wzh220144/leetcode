class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), [](const int32_t a, const int32_t b) {
            return a < b;
        });
        int32_t left = 0;
        int32_t right = people.size() - 1;
        int32_t res = 0;
        while(left <= right) {
            if (left == right) {
                ++res;
                break;
            }
            if (people[left] + people[right] > limit) {
                ++res;
                --right;
            } else {
                ++res;
                --right;
                ++left;
            }
        }
        return res;
    }
};