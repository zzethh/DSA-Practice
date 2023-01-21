vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int, int> m;
    int d = 0;
    for (int i = 0; i < B; i++) {
        m[A[i]]++;
        if (m[A[i]] == 1) d++;
    }
    vector<int> ans;
    ans.push_back(d);
    for (int i = B; i < A.size(); i++) {
        m[A[i]]++;
        if (m[A[i]] == 1) d++;

        m[A[i - B]]--;
        if (m[A[i - B]] == 0) d--;
        ans.push_back(d);
    }
    return ans;
}
