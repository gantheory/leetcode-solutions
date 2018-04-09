class Solution {
 public:
  string change(string& s) {
    vector<string> sv = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                         "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                         "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                         "...-", ".--",  "-..-", "-.--", "--.."};
    string ans;
    for (char& c : s) ans += sv[c - 'a'];
    return ans;
  }
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> st;
    for (auto& s : words) st.insert(change(s));
    return st.size();
  }
};
