class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> max1(n);
    vector<int> max2(n);

    int rolling_s1 = 0;
    int rolling_s2 = 0;
    int max_total = 0;
    for (int i = 0; i < n; i++) {
      rolling_s1 += nums[i];
      rolling_s2 += nums[i];
      if (i >= (firstLen - 1)) {
        if (i != firstLen - 1) {
          rolling_s1 -= nums[i - firstLen];
          max1[i] = std::max(rolling_s1, max1[i - 1]);
        } else
          max1[i] = rolling_s1;
      }
      if (i >= (secondLen - 1)) {
        if (i != secondLen - 1) {
          rolling_s2 -= nums[i - secondLen];
          max2[i] = std::max(rolling_s2, max2[i - 1]);
        } else
          max2[i] = rolling_s2;
      }

      if ((i + 1) >= firstLen + secondLen) {
        // assume the first one ends here and the second is before
        max_total = std::max(max_total, rolling_s1 + max2[i - firstLen]);
        // assume the second one ends here and the first one is before
        max_total = std::max(max_total, rolling_s2 + max1[i - secondLen]);
      }
    }

    return max_total;
  }
};