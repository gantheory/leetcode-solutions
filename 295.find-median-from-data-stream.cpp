class MedianFinder {
 public:
  int sz;
  multiset<int> s1, s2;
  /** initialize your data structure here. */
  MedianFinder() : sz(0) {}

  void addNum(int num) {
    if (sz == 0) {
      s2.insert(num);
      ++sz;
      return;
    }
    if (sz & 1) {
      int now = *s2.begin();
      if (num > now) {
        s1.insert(now);
        s2.erase(s2.find(now));
        s2.insert(num);
      } else {
        s1.insert(num);
      }
    } else {
      int a = *s1.rbegin(), b = *s2.begin();
      if (a < num) {
        s2.insert(num);
      } else {
        s1.erase(s1.find(a));
        s1.insert(num);
        s2.insert(a);
      }
    }
    ++sz;
  }

  double findMedian() {
    if (sz & 1)
      return (double)*s2.begin();
    else {
      return ((double)*s1.rbegin() + (double)*s2.begin()) / 2.0;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
