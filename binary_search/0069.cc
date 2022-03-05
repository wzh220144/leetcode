class Solution {
public:
  int mySqrt(int x) {
    int64_t high = x;
    int64_t low = 0;
    int64_t t = x;
    while (low <= high) {
      int64_t mid = low + ((high - low) >> 1);
      int64_t mid2 = mid * mid;
      if (mid2 < t) {
        if ((mid + 1ll) * (mid + 1ll) > t) {
          return mid;
        }
        low = mid + 1;
      } else if (mid2 == t) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return 0;
  }
};