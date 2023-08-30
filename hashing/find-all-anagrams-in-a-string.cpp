class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.length();
        if (k > s.length()) return {};
        vector<int> v(26, 0);
        map<vector<int>, int> m1;
        vector<int> ans;
        for (auto x : p) {
            v[x - 'a']++;
        }
        m1[v]++;
        for (int i = 0; i <= s.length() - k; i++) {
            vector<int> x(26, 0);
            for (int j = i; j < i + k; j++) {
                x[s[j] - 'a']++;
            }
            if (m1.find(x) != m1.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};