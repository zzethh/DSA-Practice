class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int> v;
        for (auto x : time) {
            int i = 0;
            string t = "";
            while (x[i] != ':') {
                t += x[i];
                i++;
            }
            int hr = stoi(t);
            if (hr == 0) hr = 24;
            hr = hr * 60;
            t = x.substr(i + 1);
            int mi = hr + stoi(t);
            v.push_back(mi);
        }
        int diff = INT_MAX;
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++) {
            diff = min(diff, v[i] - v[i - 1]);
        }
        int last = (v[0] + 1440) - v[v.size() - 1];
        diff = min(diff, last);
        return diff;
    }
};