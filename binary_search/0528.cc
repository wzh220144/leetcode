#include <iostream>
#include <random>

class Solution {
public:
  vector<float> weights;
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::uniform_real_distribution<float> dis{0.0, 1.0};

  Solution(vector<int> &w) {
    float sum = 0.0;
    for (const auto &x : w) {
      sum += static_cast<float>(x);
    }
    float pre = 0;
    for (const auto &x : w) {
      weights.emplace_back(pre);
      pre += x / sum;
    }
    weights.emplace_back(1.0);
  }

  bool equal(float x, float y) {
    if (fabs(x - y) <= 1e-6) {
      return true;
    } else {
      return false;
    }
  }

  int pickIndex() {
    float r = dis(gen);

    int32_t low = 0;
    int32_t high = weights.size() - 1;
    while (low <= high) {
      int32_t mid = low + ((high - low) >> 1);
      if (r < weights[mid]) {
        if (weights[mid - 1] < r) {
          return mid - 1;
        }
        high = mid - 1;
      } else if (equal(weights[mid], r)) {
        return mid;
      } else {
        if (weights[mid + 1] > r) {
          return mid;
        }
        low = mid + 1;
      }
    }
    return low;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */