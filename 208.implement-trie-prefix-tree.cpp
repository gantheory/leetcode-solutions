class Node {
 public:
  char c;
  unordered_map<char, int> mp;

  Node(char _c) : c(_c) {}
};
class Trie {
 public:
  vector<Node> t;
  /** Initialize your data structure here. */
  Trie() { t.push_back('@'); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    word += "@";
    int now = 0;
    for (int i = 0; i < (int)word.size(); ++i) {
      if (t[now].mp.count(word[i]) == 0) {
        t[now].mp[word[i]] = t.size();
        t.push_back(Node(word[i]));
      }
      now = t[now].mp[word[i]];
    }
  }

  /** Returns if the word is in the trie. */
  bool search(string word) { return startsWith(word + "@"); }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    int now = 0;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      if (t[now].mp.count(prefix[i]) == 0) return false;
      now = t[now].mp[prefix[i]];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
