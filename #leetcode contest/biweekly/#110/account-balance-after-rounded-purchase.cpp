class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int x = p;
        int y = p;
        while (x % 10 != 0) {
            x--;
        }
        while (y % 10 != 0) {
            y++;
        }
        int ans = 0;
        if (abs(x - p) == abs(y - p)) {
            ans = max(y, x);
        }
        else if (abs(x - p) < abs(y - p)) {
            ans = x;
        }
        else ans = y;
        return abs(100 - ans);
    }
};