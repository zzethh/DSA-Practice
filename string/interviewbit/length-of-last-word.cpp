int Solution::lengthOfLastWord(const string A) {
    int i = A.length() - 1;
    while (!isalpha(A[i])) {
        i--;
    }
    int cnt = 0;
    while (A[i] != ' ' and i >= 0) {
        cnt++;
        i--;
    }
    return cnt;
}
