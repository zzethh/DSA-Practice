int Solution::singleNumber(const vector<int> &A) {
    int mul = 1;
    int ans = 0;
    int mul2 = 1;
    for (int j = 0; j < 32; j++) {
        int cnto = 0;
        int cntz = 0;
        for (int i = 0; i < A.size(); i++) {
            int y = A[i] & (1 << j);
            if (y)cnto++;
            else cntz++;
        }
        if (cnto % 3 != 0) ans = ans + (1 * mul);
        mul = mul * 2;
    }
    return ans;
}
