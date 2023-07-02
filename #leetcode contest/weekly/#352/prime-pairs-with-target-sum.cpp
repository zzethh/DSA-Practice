class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1]  = false;
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == true) {
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                s.insert(i);
            }
        }
        vector<bool> vis(n + 1, 0);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) {
                if (vis[i]) continue;
                int target = n - i;
                if (s.find(target) != s.end()) {
                    vis[i] = 1;
                    vis[n - i] = 1;
                    if (i < n - i) ans.push_back({i, n - i});
                    else ans.push_back({n - i, i});
                }
            }
        }
        return ans;
    }
};