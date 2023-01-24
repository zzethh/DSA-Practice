string Solution::solve(string A, string B) {
    vector<int> a(10, 0);
    vector<int> b(10, 0);
    int x = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == B[i]) x++;
        else {
            a[A[i] - '0']++;
            b[B[i] - '0']++;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += min(a[i], b[i]);
    }
    string s = to_string(x) + 'A' + to_string(sum) + 'B';
    return s;
}
