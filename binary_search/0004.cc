class Solution {
public:
  double find_k(vector<int32_t> &nums1, vector<int32_t> &nums2, int32_t k,
                int32_t l1, int32_t h1, int32_t l2, int32_t h2) {
    int32_t len1 = h1 - l1 + 1;
    int32_t len2 = h2 - l2 + 1;
    if (len1 == 0) {
      return nums2[l2 + k - 1];
    }
    if (len1 > len2) {
      return find_k(nums2, nums1, k, l2, h2, l1, h1);
    }
    if (k == 1) {
      return min(nums1[l1], nums2[l2]);
    }

    int32_t i = min(len1, k / 2);
    int32_t j = min(len2, k / 2);
    if (nums1[l1 + i - 1] > nums2[l2 + j - 1]) {
      return find_k(nums1, nums2, k - j, l1, h1, l2 + j, h2);
    } else {
      return find_k(nums1, nums2, k - i, l1 + i, h1, l2, h2);
    }
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int32_t l1 = nums1.size();
    int32_t l2 = nums2.size();
    int32_t l = l1 + l2;
    if (l % 2) {
      return find_k(nums1, nums2, l / 2 + 1, 0, l1 - 1, 0, l2 - 1);
    } else {
      return (find_k(nums1, nums2, l / 2, 0, l1 - 1, 0, l2 - 1) +
              find_k(nums1, nums2, l / 2 + 1, 0, l1 - 1, 0, l2 - 1)) *
             0.5;
    }
  }
};