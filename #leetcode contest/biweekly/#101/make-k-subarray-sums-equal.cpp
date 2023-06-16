class Solution {
public:
    long long helper(vector<int> &v) {
        int n = v.size();
        long long ans = 0;
        if (n % 2 == 0) {
            long long med = v[n / 2];
            long long med2 = v[(n - 1) / 2];
            long long ans2 = 0;
            for (auto x : v) {
                ans += abs(med - x);
            }
            for (auto y : v) {
                ans2 += abs(med2 - y);
            }
            return min(ans, ans2);
        }
        else {
            long long med = v[n / 2];
            for (auto x : v) {
                ans += abs(med - x);
            }
        }
        return ans;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;
        int n = arr.size();
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> temp;
            long long j = i;
            while (vis[j % n] != 1) {
                vis[j % n] = 1;
                temp.push_back(arr[j % n]);
                j += k;
            }
            sort(temp.begin(), temp.end());
            ans += helper(temp);
        }
        return ans;
    }
};