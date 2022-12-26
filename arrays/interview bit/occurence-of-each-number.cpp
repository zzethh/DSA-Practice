vector<int> Solution::findOccurences(vector<int> &A) {
    map<int, int> m;
    for (int i = 0; i < A.size(); i++) {
        m[A[i]]++;
    }
    vector<int> v;
    for (auto x : m) {
        v.push_back(x.second);
    }
    //sort(v.begin(),v.end(),greater<int>());
    return v;
}
