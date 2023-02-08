class Solution {
public:
    int pivotInteger(int n) {
        vector<int> pref;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i;
            pref.push_back(ans);
        }

        for (int j = 0; j < n; j++) {
            if (j == 0) {
                if (pref[j] == pref[n - 1]) {
                    return 1;
                }
                continue;
            }
            if (pref[j] == pref[n - 1] - pref[j - 1]) {
                return j + 1;
            }
        }

        return -1;
    }
};