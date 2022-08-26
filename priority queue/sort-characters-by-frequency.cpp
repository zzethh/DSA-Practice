class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> p;

        for (auto &i : m) {
            p.push({i.second, i.first});
        }

        string ans = "";
        while (!p.empty()) {
            auto x = p.top();
            p.pop();
            int cnt = x.first;
            while (cnt--) {
                ans += x.second;
            }
        }
        return ans;
    }
};