int Solution::solve(string A) {
    int i = 0;
    int n = A.length() - 1;
    int j = n;
    int last_i = j;
    while (i <= j) {
        if (A[i] == A[j]) {
            i++;
            j--;
        }
        else {
            i = 0;
            j = --last_i;
        }
    }
    return n - last_i;
}
