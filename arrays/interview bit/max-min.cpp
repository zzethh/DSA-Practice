int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int sum = A[0] + A[A.size() - 1];
    return sum;
}
