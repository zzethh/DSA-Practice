int Solution::divide(int a, int b) {
    long long ans = 0;
    long long A = a, B = b;
    if (A == 0) return 0;
    if (B == 0) return INT_MAX;
    int sign = 1;
    if ((A > 0 and B < 0) or (A<0 and B>0)) sign = -1;
    A = abs(A);
    B = abs(B);
    for (int i = 31; i >= 0; i--) {
        long long x = B << i;
        if (A < x) continue;
        else A = A - x, ans = ans + (1ll << i);
    }
    ans = sign * ans;
    if (ans > INT_MAX or ans < INT_MIN) return INT_MAX;
    return ans;
}
