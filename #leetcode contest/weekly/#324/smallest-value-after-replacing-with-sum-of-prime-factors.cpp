class Solution {
public:
    int fac(int n) {
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
        int sum = 0;
        for (auto x : v) {
            sum += x;
        }
        return sum;
    }
    int smallestValue(int n) {
        //int temp=fac(n);
        // int sum=0;
        //cout<<fac(5);
        while (fac(n) != n) {
            //cout<<fac(n)<<endl;
            //          sum+=fac(n);
            n = fac(n);
//temp=fac(temp);
        }
        return n;
    }
};