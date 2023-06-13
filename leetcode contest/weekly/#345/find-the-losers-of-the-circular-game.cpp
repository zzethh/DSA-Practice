class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        int i = 1;
        int next = 0;
        while (m.find(next) == m.end()) {
            m[next]++;
            next = (next + (i * k)) % (n);
            i++;
        }
        for (int i = 0; i < n; i++) {
            if (!m[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};