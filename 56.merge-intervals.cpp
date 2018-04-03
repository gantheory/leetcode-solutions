/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  static bool compare(Interval& a, Interval& b) {
    if (a.start != b.start) return (a.start < b.start);
    return (a.end < b.end);
  }
  vector<Interval> merge(vector<Interval>& intervals) {
    if (!intervals.size()) return vector<Interval>();
    vector<Interval> ans;
    sort(intervals.begin(), intervals.end(), compare);
    ans.push_back(intervals[0]);
    for (int i = 1; i < (int)intervals.size(); ++i) {
      if (intervals[i].start <= ans.back().end)
        ans.back().end = max(ans.back().end, intervals[i].end);
      else
        ans.push_back(intervals[i]);
    }
    return ans;
  }
};
