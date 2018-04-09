class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    int ra = stoi(a.substr(0, a.find('+')));
    int ia = stoi(a.substr(a.find('+') + 1));
    int rb = stoi(b.substr(0, b.find('+')));
    int ib = stoi(b.substr(b.find('+') + 1));
    string ans = to_string(ra * rb - ia * ib) + "+";
    ans += to_string(ra * ib + ia * rb) + "i";
    return ans;
  }
};
