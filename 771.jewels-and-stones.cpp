class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> st;
    for (char& c : J) st.insert(c);

    int ans = 0;
    for (char& c : S) ans += st.count(c);
    return ans;
  }
};
