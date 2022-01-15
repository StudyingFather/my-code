class GuessForMoney {
 public:
  double balance(long long N) {
    double ans = 0;
    for (long long i = 0, sum = 0;; sum += (1ll << i), i++) {
      if (sum + (1ll << i) >= N) {
        ans += (N - sum) * 1.0 / N * (i + 1);
        return ans;
      }
      ans += (1ll << i) * 1.0 / N * (i + 1);
    }
  }
};