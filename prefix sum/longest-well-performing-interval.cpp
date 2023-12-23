class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> pref;
        unordered_map<int, int> m;
        int score = 0;
        int ans = 0;
        for (int i = 0; i < hours.size(); i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                ans = max(ans, i + 1);
            }
            else {
                if (m.find(score - 1) != m.end()) {
                    ans = max(ans, i - m[score - 1]);
                }

                if (m.find(score) == m.end()) m[score] = i;
            }
        }
        return ans;
    }
};