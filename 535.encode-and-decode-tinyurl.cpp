class Solution {
 public:
  vector<string> v;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    int ans = v.size();
    v.push_back(longUrl);
    return to_string(ans);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) { return v[stoi(shortUrl)]; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
