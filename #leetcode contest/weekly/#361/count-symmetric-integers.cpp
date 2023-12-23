class Solution {
public:
    bool valid(int x) {
        vector<int> v;
        while (x) {
            int rem = x % 10;
            x = x / 10;
            v.push_back(rem);
        }
        int n = v.size();
        if (n % 2 != 0) return false;
        int mid = n / 2 - 1;
        int start = 0;
        for (int i = 0; i <= mid; i++) {
            start += v[i];
        }
        int last = 0;
        for (int i = n - 1; i > mid; i--) {
            last += v[i];
        }
        return start == last;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            if (valid(i)) cnt++;
        }
        return cnt;
    }
};