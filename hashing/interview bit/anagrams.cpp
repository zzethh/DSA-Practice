vector<int> hashf(string s) {
    vector<int> v(26, 0);
    for (int i = 0; i < s.length(); i++) {
        v[s[i] - 'a']++;
    }
    return v;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    map<vector<int>, vector<int>> m;
    for (int i = 0; i < A.size(); i++) {
        vector<int> h = hashf(A[i]);
        m[h].push_back(i + 1);
    }
    vector<vector<int>> ans;
    for (auto x : m) {
        if (x.second.size() >= 1) {
            ans.push_back(x.second);
        }
    }
    return ans;
}
