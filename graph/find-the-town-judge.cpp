class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        if (n == 1) return 1;

        map<int, int> trusted;
        for (auto x : trust) {
            trusted[x[1]]++;
        }

        map<int, int> will_trust;
        for (auto y : trust) {
            will_trust[y[0]]++;
        }

        for (int i = 0; i <= n; i++) {
            if (will_trust[i] == 0 and trusted[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};