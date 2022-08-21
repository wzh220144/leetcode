class Solution {
public:
  double find_k(const int32_t k, const vector<int32_t> &nums1, const vector<int32_t> &nums2, 
                const int32_t s1, const int32_t e1, const int32_t s2, const int32_t e2) {
    int32_t l1 = e1 - s1 + 1;
    int32_t l2 = e2 - s2 + 1;
    if (l1 <= 0) {
      return nums2[s2 + k - 1];
    }
    if (l1 > l2) {
      return find_k(k, nums2, nums1, s2, e2, s1, e1);
    }
    if (k == 1) {
      return min(nums1[s1], nums2[s2]);
    }

    int32_t mid = 0;
    int32_t i = std::min(l1, k / 2);
    int32_t j = std::min(l2, k / 2);
    if (nums1[i + s1 - 1] > nums2[j + s2 - 1]) {
        return find_k(k - j, nums1, nums2, s1, e1, j + s2, e2);
    } else {
        return find_k(k - i, nums1, nums2, i + s1, e1, s2, e2);
    }
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int32_t l1 = nums1.size();
    int32_t l2 = nums2.size();
    int32_t l = l1 + l2;
    if (l % 2) {
      return find_k(l / 2 + 1, nums1, nums2, 0, l1 - 1, 0, l2 - 1);
    } else {
      return (find_k(l / 2, nums1, nums2, 0, l1 - 1, 0, l2 - 1) +
              find_k(l / 2 + 1, nums1, nums2, 0, l1 - 1, 0, l2 - 1)) *
             0.5;
    }
  }
};