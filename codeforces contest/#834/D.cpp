#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

int trailingZero(int n) {
	int cnt = 0;
	int div = 10;
	while (1) {
		if (n % div == 0) cnt++;
		else break;
		n = n / div;
	}
	return cnt;
}


int main()
{
	ll t, n, m, k, i, j, ans, mul;

	cin >> t;

	for (; t--;)
	{
		cin >> n >> m;

		k = 1; ans = n;


		while ((n % 10) == 0) {
			n /= 10;

		}

		while ((n % 5) == 0) {
			n = n / 5;

			if ((k * 2 <= m))
				k = k * 2;
			else
				break;
		}

		while ((n % 2) == 0) {
			n /= 2;

			if ((k * 5) <= m) {
				k = k * 5;
			} else {
				break;
			}
		}

		while ((k * 10) <= m) {
			k = k * 10;
		}

		k = (m / k) * k;

		cout << ans*k << "\n";

	}
}
