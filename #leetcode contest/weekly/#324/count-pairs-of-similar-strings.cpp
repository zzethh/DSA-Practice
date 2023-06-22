class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<vector<int>, int> m;
        for (auto x : words) {
            vector<int> v(26, 0);
            for (auto c : x) {
                v[c - 'a'] = 1;
            }
            m[v]++;
        }
        int cnt = 0;
        for (auto x : m) {
            if (x.second >= 2) {
                int n = x.second;
                cnt += (n * (n - 1)) / 2;
            }
            // cout<<endl;
        }
        return cnt;
    }
};