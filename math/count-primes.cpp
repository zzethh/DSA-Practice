class Solution {
public:
    // bool isPrime(int n){
    //     for(int i=2;i<=sqrt(n);i++){
    //         if(n%i==0) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1] = isPrime[n] = false;
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == true) {
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int cnt = 0;
        for (auto x : isPrime) {
            if (x) cnt++;
        }
        return cnt;
    }
};