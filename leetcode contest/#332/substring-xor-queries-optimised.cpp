class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int v = 0;
                for (int j = i; j < min(n, i + 30); j++) {
                    v = (v << 1) + (s[j] - '0');
                    if (!m.count(v)) {
                        m[v] = {i, j};
                    }
                }
            }
            else if (!m.count(0)) {
                m[0] = {i, i};
            }
        }
        vector<vector<int>> ans;
        for (auto q : queries) {
            int v = q[0] ^ q[1];
            if (m.count(v)) {
                ans.push_back(m[v]);
            }
            else {
                ans.push_back({ -1, -1});
            }
        }
        return ans;
    }
};