long long mod = pow(10, 9) + 7;
int Solution::solve(int A) {
    if (A == 0) return 0;
    if (A == 1) return 1;
    int n = 1;
    int x = 0;
    while (n <= A) {
        n = n * 2;
        x++;
    }
    //while((1<<x)<=n) x++;
    x--;
    //long long x=log2(A);
    long long a = pow(2, x - 1) * x;
    long long b = A - pow(2, x) + 1;
    long long c = A - pow(2, x);
    long long ans = a + b + solve(c);
    return ans % mod;
}
