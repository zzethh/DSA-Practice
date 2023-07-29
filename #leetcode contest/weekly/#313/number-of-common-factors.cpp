class Solution {
public:
    int commonFactors(int a, int b) {
        int cnt = 0;
        //if(b<a) commonFactors(b,a);
        if (a <= b) {
            for (int i = 1; i <= a; i++) {
                if (b % i == 0 and a % i == 0) {
                    cnt++;
                }
            }
        }
        else {
            for (int i = 1; i <= b; i++) {
                if (b % i == 0 and a % i == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};