class Solution {
public:
//     void findprime(int n,unordered_map<int,int> &m) {
//         int num=n;
//         vector<bool> isPrime(n+1, 1);

//         //isPrime[0] = isPrime[1]  = false;
//         for (int i = 2; i*i <= n; i++) {
//             if (isPrime[i] == true) {
//                 for (int j = i * i; j <= n; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }
//         for(int i=2;i<=n;i++){

//         }
//     }

    // void findprime(int n,unordered_map<int,int> &m){
    //     vector<int> spf(n+1,0);
    //     for(long long i=2;i<=n;i++){
    //         spf[i]=i;
    //     }
    //     for(long long i=2;i<=n;i++){
    //         if(spf[i]==i){
    //             for(long long j=i*i;j<=n;j+=i){
    //                 if(spf[j]==j){
    //                     spf[j]=i;
    //                 }
    //             }
    //         }
    //     }
    //     while(n!=1){
    //         m[spf[n]]++;
    //         n=n/spf[n];
    //     }
    // }

    vector<int> findprime(int n) {
        vector<int> v;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                v.push_back(i);
                n = n / i;
            }
        }
        if (n > 1) {
            v.push_back(n);
        }
        return v;
    }
    int findValidSplit(vector<int>& nums) {
        int max_right = 0;
        int n = nums.size();
        if (n == 1) return -1;
        unordered_map<int, int> mr;
        unordered_map<int, int> ml;
        unordered_map<int, vector<int>> pfv;

        for (int i = 0; i < n; i++) {
            vector<int> pf = findprime(nums[i]);
            pfv[i] = pf;
            for (auto x : pf) {
                mr[x] = i;
                if (ml.find(x) == ml.end()) {
                    ml[x] = i;
                }
            }
        }
        int rightcap = n;
        for (int i = n - 1; i >= 0; i--) {
            vector<int> pf = pfv[i];
            for (auto x : pf) {
                rightcap = min(rightcap, ml[x]);
            }
            if (i - 1 < rightcap) break;
        }
        int leftcap = 0;
        for (int i = 0; i < n; i++) {
            vector<int> pf = pfv[i];
            for (auto x : pf) {
                leftcap = max(leftcap, mr[x]);
            }
            if (i + 1 > leftcap) break;
        }

        if (rightcap <= leftcap) return -1;
        return leftcap;
    }
};