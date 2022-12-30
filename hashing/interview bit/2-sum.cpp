bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_set<int> s;
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    for (int i = 0; i < A.size(); i++) {
        int x = B - A[i];
        if (s.find(x) != s.end()) {
            ans.push_back({m[x], i + 1});
        }
        if (m.find(A[i]) == m.end()) m[A[i]] = i + 1;
        s.insert(A[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    if (!ans.empty()) return ans[0];
    return {};
}
