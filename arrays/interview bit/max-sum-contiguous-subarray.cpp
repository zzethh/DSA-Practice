int Solution::maxSubArray(const vector<int> &A) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        if (currentSum < 0) {
            currentSum = A[i];
        }
        else currentSum += A[i];
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}
