#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool solve(int n, int mid, vector<int>&v, int c, int d) {

    if (n > mid) {

        int time = d / (mid + 1);
        int x = d % (mid + 1);
        int sum = 0;
        for (int i = 0; i <= mid; i++) {
            sum += v[i];
        }

        sum = sum * time;
        for ( int i = 0; i <  x; i++)
        {
            sum += v[i];
        }

        if (sum >= c) {
            return true;
        }
        else
        {
            return false;
        }



    }
    else
    {
        int time = d / (mid + 1);
        int x = d % (mid + 1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
        }

        sum = sum * time;
        for ( int i = 0; i <  min(x, n); i++)
        {
            sum += v[i];
        }
        //  cout<<sum<<endl;

        if (sum >= c) {
            return true;
        }
        else
        {
            return false;
        }


    }

    return true;

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while ( t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int>v(n);
        for ( int i = 0; i <  n; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int val = v[n - 1] * d;
        //   cout<<1<<endl;
        if (c > val) {
            cout << "Impossible" << endl;
            continue;
        }

        int mn = min(n, d);
        int ind = n - 1;
        int cost = 0;
        while ( mn--)
        {
            cost += v[ind];
            ind--;

        }

        if (cost >= c) {
            cout << "Infinity" << endl;
            continue;
        }


        reverse(v.begin(), v.end());

        int hi = d;
        int lo = 0;

        int ans = 0;
        while ( hi >= lo)
        {
            int mid = (lo + hi) / 2;

            if (solve(n, mid, v, c, d) == true) {
                ans = mid;
                // cout<<ans<<endl;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        cout << ans << endl;





    }

}