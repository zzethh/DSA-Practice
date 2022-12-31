int Solution::sqrt(int A) {
    long s = 0;
    long e = A;
    long n = 0;
    while (s <= e) {
        long mid = (s + e) / 2;
        if (mid * mid == A) {
            return mid;
        }
        else if (mid * mid < A) {
            n = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    return n;
}
