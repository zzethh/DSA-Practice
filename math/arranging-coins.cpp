class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        bool complete = false;
        while (n > 0) {
            i++;
            n -= i;
        }
        if (n == 0) complete = true;
        int result = (complete == true) ? i : i - 1;
        return result;
    }
};