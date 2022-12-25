#include<bits/stdc++.h>
using namespace std;


using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

ll cout_days(ll k, ll days) {
	ll cnt = 1;
	ll i = 1;
	while (i + k + 1 <= days) {
		i = i + k + 1;
		cnt++;
	}
	return k;
}
bool cank(vector<ll> qvalue, ll k, ll coin, ll days) {
	int i = 0;
	ll max_done = 0;
	ll max_day = 1;
	while (max_done < coin) {
		if (i == qvalue.size()) return false;
		max_done += (cout_days(k, days)) * qvalue[i];
		days = days - (cout_days(k, days));
		i++;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> qvalue;
		ll coin;
		cin >> coin;
		ll days;
		cin >> days;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			qvalue.pb(x);
		}
		ll s = 1;
		ll e = days;
		ll ans = 0;
		sort(qvalue.begin(), qvalue.end(), greater<int>());
		if (days * qvalue[0] < coin) {
			cout << "Impossible" << endl;
			continue;
		}
		else if (days * qvalue[0] == coin) {
			cout << "0";
			continue;
		}
		while (s <= e) {
			int mid_k = (s + e) / 2;
			if (cank(qvalue, mid_k, coin, days)) {
				cout << mid_k << " ";
				ans = mid_k;
				s = mid_k + 1;
			}
			else e = mid_k - 1;
		}
		if (ans == days) cout << "Infinity";
		else cout << ans;

		cout << endl;

	}
	cout << endl;
	int cnt = 1;
	int i = 1;
	int k = 2;
	while (i + k + 1 <= 2) {
		i = i + k + 1;
		cnt++;
	}
	cout << cnt;


	return 0;
}

