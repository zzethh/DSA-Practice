class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        vector<int> v = nums;
        for (auto x : nums) {
            v.push_back(x);
        }
        map<int, int> m;
        int ans = INT_MAX;
        map<int, int> diff;
        for (int i = 0; i < v.size(); i++) {
            if (m.find(v[i]) == m.end()) {
                m[v[i]] = i;
                continue;
            }
            else {
                int d = i - m[v[i]];
                if (diff.find(v[i]) == diff.end() or d > diff[v[i]]) {
                    diff[v[i]] = d;
                }
                m[v[i]] = i;
            }
        }
        for (auto d : diff) {
            ans = min(ans, d.second / 2);;
        }
        return ans;
    }
};