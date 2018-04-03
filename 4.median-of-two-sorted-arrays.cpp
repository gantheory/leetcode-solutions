class Solution {
 public:
  double findKth(vector<int>& a, int al, int ar, vector<int>& b, int bl, int br,
                 int k) {
    if (al > ar) return b[bl + k - 1];
    if (bl > br) return a[al + k - 1];

    int aMid = (al + ar) >> 1;
    int bMid = (bl + br) >> 1;

    if (a[aMid] <= b[bMid]) {
      if (k <= (aMid - al + 1 + bMid - bl))
        return findKth(a, al, ar, b, bl, bMid - 1, k);
      else
        return findKth(a, aMid + 1, ar, b, bl, br, k - (aMid - al + 1));
    } else {
      if (k <= (aMid - al + bMid - bl + 1))
        return findKth(a, al, aMid - 1, b, bl, br, k);
      else
        return findKth(a, al, ar, b, bMid + 1, br, k - (bMid - bl + 1));
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int k = (nums1.size() + nums2.size() + 1) >> 1;
    double v =
        findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, k);
    if ((nums1.size() + nums2.size()) & 1) return v;
    return (findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1,
                    k + 1) +
            v) /
           2.0;
  }
};
