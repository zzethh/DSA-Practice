class Solution {
public:
    int twoEggDrop(int n) {
        int x = 0;
        int diff = 0;
        while (n >= 1) {
            n = n - diff;
            diff++;
            x++;
        }
        return x - 1;
    }
};