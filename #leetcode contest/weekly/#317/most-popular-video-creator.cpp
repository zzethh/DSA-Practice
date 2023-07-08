class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> ans;
        map<string, long long> m;
        map<string, pair<int, string>> m2;
        for (int i = 0; i < ids.size(); i++) {
            if (m2.find(c[i]) != m2.end()) {
                int v = m2[c[i]].first;
                string d = m2[c[i]].second;
                if (views[i] > v) {
                    m2[c[i]] = {views[i], ids[i]};
                }
                else if (views[i] == v) {
                    if (d > ids[i]) {
                        m2[c[i]] = {views[i], ids[i]};
                    }
                }
            }
            else {
                m2[c[i]] = {views[i], ids[i]};
            }
        }
        for (int i = 0; i < ids.size(); i++) {
            m[c[i]] += views[i];
        }
        // vector<string> maxi;
        long long maxii = INT_MIN;
        for (auto x : m) {
            maxii = max(maxii, x.second);
        }
        for (auto x : m) {
            if (x.second == maxii) {
                ans.push_back({x.first, m2[x.first].second});
            }
        }
        return ans;
    }
};