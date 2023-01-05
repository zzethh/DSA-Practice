class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = ~0;
        for (long i = left; i <= right; i++) {
            ans = ans & i;
            if (ans == 0) break;
        }
        return ans;
    }
};