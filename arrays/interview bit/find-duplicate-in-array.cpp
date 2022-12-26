int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size() - 1;
    vector<int> v = A;
    for (int i = 0; i < v.size(); i++) {
        int element = v[i];
        int chair = element - 1;
        if (v[chair] != element) {
            swap(v[chair], v[i]);
            i--;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i + 1) {
            return v[i];
        }
    }

    return -1;
}
