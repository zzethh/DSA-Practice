#include<bits/stdc++.h>

using namespace std;

int lotteryCoupons(int n) {
    //vector<int> winners(9 * n, 0);
    map<int, int> winners;
    int maxWinners = 0;

    vector<int> coupons(n);
    for (int i = 0; i < n; i++) {
        coupons[i] = i + 1;
    }
    int maxSum = INT_MIN;
    int largest = -1;
    for (int i = 0; i < n; i++) {
        int coupon = coupons[i];
        int sum = 0;
        while (coupon > 0) {
            sum += coupon % 10;
            coupon /= 10;
        }
        winners[sum]++;
        // if(sum>maxSum){
        //     maxSum=sum;
        //     largest=winners[sum];
        // }
        // maxWinners = max(maxWinners, winners[sum]);
    }
    int ans = 0;
    for (auto x : winners) {
        if (x.second > largest) {
            largest = x.second;
            //ans=x.first;
        }
    }

    int count = 0;
    for (auto x : winners) {
        if (x.second == largest) {
            count++;
        }
    }
    return count;
    //return winners[ans];

    // int count=0;
    // for(int i = 1; i <= 9 * n; i++){
    //     if(i==maxSum and winners[i]==largest){
    //         count++;
    //     }
    // }
    // int count = 0;
    // for (int i = 1; i <= 9 * n; i++) {
    //     if (winners[i % 9 + 1] == maxWinners && i >= maxWinners) {
    //         count++;
    //     }
    // }
    // return winners[maxSum];
    //return count;

    //return maxWinners;
}

int main() {
    int n;
    cin >> n;

    // vector<int> coupons(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> coupons[i];
    // }

    cout << lotteryCoupons(n) << endl;

    return 0;
}
