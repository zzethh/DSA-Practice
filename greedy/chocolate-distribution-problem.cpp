class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        //code
        sort(a.begin(), a.end());
        int min = INT_MAX;
        for (int i = 0; i < n - m + 1; i++) {
            if (a[i + m - 1] - a[i] < min) {
                min = a[i + m - 1] - a[i];
            }
        }
        return min;
    }
};