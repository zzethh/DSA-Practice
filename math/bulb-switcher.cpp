class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) return 0;
        int i = 3;
        int total = 0;
        int ans = 0;
        while (total < n) {
            total += i;
            i += 2;
            ans++;
        }

        return ans;
    }
};