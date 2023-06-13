class Solution {
public:
    bool helper(int x) {
        return (x & (x - 1)) == 0;
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    bool isReachable(int targetX, int targetY) {
        if (helper(targetX) or helper(targetY) or helper(gcd(targetX, targetY))) return true;
        return false;
    }
};
