int minimumDays(int S, int N, int M) {
    // code here
    int req = M * S;
    if (M > N) return -1;
    int cnt = 0;
    int sum = 0;
    int day = 1;
    while (sum < req) {
        if (day % 7 == 0) {
            day++;
            continue;
        }
        sum = sum + N;
        cnt++;
        day++;
    }
    if (S < day - 1) return -1;
    return cnt;
}