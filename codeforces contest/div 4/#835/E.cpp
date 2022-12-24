#include<bits/stdc++.h>
using namespace std;


using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll cnti = 0;
		ll cnt = 0;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
			if (x == 1) cnt++;
			else cnti = cnti + cnt;
		}
		cnt = 0;
		vector<int> v1 = v;
		for (int i = 0; i < n; i++) {
			if (v1[i] == 0) {
				v1[i] = 1;
				break;
			}
		}
		ll cnti2 = 0;
		for (int i = 0; i < n; i++) {
			if (v1[i] == 1) cnt++;
			else cnti2 = cnti2 + cnt;
		}

		cnt = 0;
		vector<int> v2 = v;
		for (int i = v2.size() - 1; i >= 0; i--) {
			if (v2[i] == 1) {
				v2[i] = 0;
				break;
			}
		}

		ll cnti3 = 0;
		for (int i = 0; i < n; i++) {
			if (v2[i] == 1) cnt++;
			else cnti3 = cnti3 + cnt;
		}
		cout << max(cnti, max(cnti3, cnti2));

		cout << endl;

	}


	return 0;
}

