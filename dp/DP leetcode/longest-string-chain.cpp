class Solution {
public:
    bool compare(string &s1, string &s2) {
        int i = 0;
        int j = 0;
        if (s1.length() < s2.length()) return compare(s2, s1);
        if (s1.length() != s2.length() + 1) return false;

        while (i < s1.length()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        if (i == s1.length() and j == s2.length()) {
            return true;
        }
        return false;
    }
    int LIS(vector<string> &arr, int i, int prev, vector<vector<int>> &dp) {
        if (i == arr.size()) {
            return 0;
        }

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int exc = LIS(arr, i + 1, prev, dp);
        int inc = INT_MIN;
        if (prev == -1 or compare(arr[prev], arr[i])) {
            inc = 1 + LIS(arr, i + 1, i, dp);
        }

        return dp[i][prev + 1] = max(inc, exc);

    }

    bool static cmp(string a, string b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<vector<int>> dp(words.size(), vector<int>(words.size() + 1, -1));
        return LIS(words, 0, -1, dp);
    }
};