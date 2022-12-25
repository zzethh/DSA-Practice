int Solution::solve(vector<int> &A, int B) {
    int curSum = 0;
    int maxSum = 0;
    int minSum = 0;
    int n = A.size() - B;
    for (int i = 0; i < A.size(); i++) {maxSum += A[i];}
    for (int i = 0; i < A.size() - n; i++) {
        curSum = 0;
        for (int j = 0; j < n; j++) {
            curSum += A[i + j];
        }
        minSum = min(curSum, minSum);
    }

    return maxSum - minSum;
}
