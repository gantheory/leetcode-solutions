class Solution {
 public:
  int countPrimes(int n) {
    vector<int> primes;
    for (int i = 2; i < n; ++i) {
      bool is_prime = true;
      for (int v : primes) {
        if (v * v > i) break;
        if (i % v == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime) primes.push_back(i);
    }
    return primes.size();
  }
};
