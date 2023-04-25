class Solution {
public:
  double fastExpo(double a, int n) {
    double ans = 1;
    while (n > 0) {
      int last_bit = (n & 1);
      if (last_bit) {
        ans = ans * a;
      }
      a = a * a;
      n = n >> 1;
    }

    return ans;
  }

  double myPow(double x, int n) {
    if (n == 0) {return 1;}
    if (x == 1) return 1;
    if (n < 0) return fastExpo(1 / x, abs(n));
    return fastExpo(x, n);
  }
};