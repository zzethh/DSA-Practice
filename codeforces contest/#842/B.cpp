#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n, 0);
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			//v.push_back(x);
			v[i] = x;
		}
		int ans = n + 1;
		int mini = n + 1;
		for (int i = n ; i >= 1; i--) {
			if (v[i] > mini) {
				ans = min(ans, v[i]);
			}
			mini = min(v[i], mini);
		}

		if (ans == n + 1) cout << 0;
		else {
			int len = (n - ans + 1);
			if (len % k == 0) cout << (len / k);
			else cout << (len / k) + 1;
		}
		cout << endl;
	}

	return 0;
}