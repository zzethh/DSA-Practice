#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

int fac(int n) {
	if (n == 0 or n == 1) {
		return 1;
	}
	return n * fac(n - 1);
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		int ans = -1;
		// for (int i = 1; i < k; i++) {
		// 	if (fac(i) % k == 0 or (i + 1) == k) ans = i;
		// }
		cout << k - 1;
		cout << endl;
	}
	//cout << fac(5);

	return 0;
}