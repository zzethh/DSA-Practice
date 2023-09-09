class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int len = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            cost += abs(s[i] - t[i]);
            if (cost > maxCost) {
                while (cost > maxCost) {
                    cost -= abs(s[j] - t[j]);
                    j++;
                }
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};