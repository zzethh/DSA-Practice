class Solution {
public:
    int bestClosingTime(string customers) {
        int mini = INT_MAX;
        int n = customers.size();
        vector<int> pref(n + 1, 0);
        int cnt = 0;
        for (int i = customers.size() - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                cnt++;
            }
            pref[i] = cnt;
        }
        cnt = 0;
        for (int i = 1; i <= customers.size(); i++) {
            if (customers[i - 1] == 'N') {
                cnt++;
            }
            pref[i] += cnt;
        }
        int miniidx = 0;
        for (int i = 0; i < pref.size(); i++) {
            if (pref[i] < mini) {
                mini = pref[i];
                miniidx = i;
            }
        }
        return miniidx;
    }
};