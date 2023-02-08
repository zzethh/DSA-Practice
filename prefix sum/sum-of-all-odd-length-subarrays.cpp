class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        vector<int> pref;
        for (auto x : arr) {
            sum += x;
            pref.push_back(sum);
        }
        int ans = 0;
        for (int i = 0; i < pref.size(); i++) {
            for (int j = i; j < pref.size(); j++) {
                if (((j - i + 1) % 2) == 1) {
                    if (i == 0) ans += pref[j];
                    else ans += pref[j] - pref[i - 1];
                }
            }
        }
        return ans;
    }
};