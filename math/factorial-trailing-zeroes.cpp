class Solution {
public:
    int trailingZeroes(int n) {
        int a = 0;
        int aa = n;
        while (aa) {
            a += aa / 5;
            aa = aa / 5;
        }
        int b = 0;
        int bb = n;
        while (bb) {
            b += bb / 2;
            bb = bb / 2;
        }
        return min(a, b);
    }
};