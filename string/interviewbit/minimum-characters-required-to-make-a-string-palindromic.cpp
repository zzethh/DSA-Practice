bool isPalin(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        else {
            i++;
            j--;
        }
    }
    return true;
}
int Solution::solve(string A) {
    int added = 0;
    int n = A.length();
    while (n > 0) {
        if (isPalin(A.substr(0, n - added))) break;
        else added++;
    }
    return added;
}
