class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long num = n;
        long long sum = 0;
        long long cnt = 0;
        while (num) {
            sum += num % 10;
            num = num / 10;
            cnt++;
        }
        cnt++;
        if (sum <= target) return 0;
        long long subs = sum - target;
        long long temp = n;
        long long x = 0;
        long long cnt2 = 0;
        long long carry = 0;
        long long prod = 1;
        while (cnt--) {
            long long rem = 0;
            if (temp) rem = temp % 10;
            long long diff = 10 - rem - (cnt2 > 0);
            sum = sum - rem + (cnt2 == 0);
            x = x + (prod * diff);
            if (sum <= target) return x;
            prod = prod * 10;
            temp = temp / 10;
            carry = 1;
            cnt2++;
        }
        return -1;
    }
};