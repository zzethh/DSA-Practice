class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> v;
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < words.size(); i++) {
            string t = words[i];
            if (s.find(t[0]) != s.end() and s.find(t[t.length() - 1]) != s.end()) {
                v.push_back(i);
                //cout<<i;
            }
        }
        vector<int> ans;
        for (auto x : queries) {
            int l = x[0];
            int r = x[1];
            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();
            ans.push_back(right - left);
        }
        return ans;
    }
};