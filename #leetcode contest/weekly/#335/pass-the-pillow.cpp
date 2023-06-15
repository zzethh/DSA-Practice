class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int t = 0;
        bool flag = true;
        int ans = 0;
        while (t <= time) {
            if (i == n) {
                flag = false;
            }
            if (i == 1) {
                flag = true;
            }
            if (flag) {
                ans = i;
                i++;
            }
            else {
                ans = i;
                i--;
            }
            t++;
        }
        return ans;

    }
};