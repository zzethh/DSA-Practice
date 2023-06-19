class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, 1);
        isPrime[0] = isPrime[1]  = false;
        for (int i = 2; i < right; i++) {
            if (isPrime[i] == true) {
                for (int j = 2 * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // for(int i=left;i<=right;i++){
        //     cout<<i<<": "<<isPrime[i]<<endl;
        // }

        int diff = INT_MAX;
        int a = -1;
        int b = -1;
        int prev = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                if (prev == INT_MAX) {prev = i; continue;}
                int x = abs(i - prev);
                cout << x << endl;
                if (x < diff) {
                    diff = x;
                    a = prev;
                    b = i;
                }
                prev = i;
            }
        }
        vector<int> ans = {a, b};
        return ans;
    }
};