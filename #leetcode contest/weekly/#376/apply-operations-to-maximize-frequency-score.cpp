typedef long long int ll;

class Solution {

    bool IsPossible (int len, const vector<int>& arr, const ll K) {
        int n = arr.size();
        if (len > n) return false;

        vector<ll> prefix(n + 1, 0);
        for (int j = 1; j <= n; j ++) prefix[j] = prefix[j - 1] + arr[j - 1];

        for (ll l = 1, r = len; r <= n; l ++, r ++) {
            ll median = (l + r) >> 1;
            ll val = arr[median - 1];

            ll less_to_median = (median - l + 1) * val - (prefix[median] - prefix[l - 1]);
            ll more_to_median = r <= median ? 0 : (prefix[r] - prefix[median]) - (r - median) * val;

            if ((less_to_median + more_to_median) <= K) return true;
        }

        return false;
    }

public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort (nums.begin(), nums.end());

        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) >> 1;

            if (IsPossible(m + 1, nums, k)) l = m + 1;
            else r = m;
        }
        return l;
    }
};