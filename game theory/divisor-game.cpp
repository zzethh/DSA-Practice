class Solution {
public:
    bool helper(int n, bool x) {
        ///if(n==1) return false;
        if (n == 2) return true;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                bool sub = helper(n - i, !x);
                if (!sub and x == 1) return true;
                if (sub and x == 0) return true;
            }
        }
        /// if(x==0) return true;
        return false;
    }
    bool divisorGame(int n) {
        // helper(n);
        ///if(n%2==0) return true;
        return helper(n, 1);
    }
};