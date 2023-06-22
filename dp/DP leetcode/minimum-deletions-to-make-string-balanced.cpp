class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        if (n == 1) return 0;
        vector<int> leftb;
        vector<int> right(n + 1, 0);
        int cnta = 0;
        int cntb = 0;
        leftb.push_back(0);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') cntb++;
            leftb.push_back(cntb);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') cnta++;
            right[i] = cnta;
        }
        int del = INT_MAX;
        for (int i = 0; i < leftb.size(); i++) {
            del = min(del, leftb[i] + right[i]);
        }
        return del;
    }
};