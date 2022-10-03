class Solution {
public:
    bool isPerfectSquare(int num) {
        long s = 0;
        long e = num;
        bool ans = false;
        while (s <= e) {
            long mid = s + (e - s) / 2;
            if (mid * mid == num) {
                ans = true;
                return true;
            }
            else if (mid * mid < num) {
                ans = false;
                s = mid + 1;
            }
            else {
                ans = false;
                e = mid - 1;
            }
        }
        return ans;
    }
};