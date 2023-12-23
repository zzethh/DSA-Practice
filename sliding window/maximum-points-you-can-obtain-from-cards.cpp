class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= card.size(); i++) {
            pref[i] = pref[i - 1] + card[i - 1];
        }
        int sum = 0;
        int ans = 0;
        cout << pref[n];
        ans = pref[n] - pref[n - k] + sum;
        int j = 0;
        for (int i = n - k + 1; i <= n; i++) {
            sum += card[j];
            ans = max(ans, pref[n] - pref[i] + sum);
            j++;
        }
        return ans;
    }
};