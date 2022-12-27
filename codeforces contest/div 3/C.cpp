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
		int k, n;
		cin >> k >> n;
		vector<int> v;
		//int i = 1;
		int x = 1;
		//v.push_back(x);
		int cnt = 1;
		//k--;
		// while (k-- ) {
		// 	//v.push_back(x + i);
		// 	if (x + i <= n and n - x > k) {
		// 		//v.push_back(x + i);
		// 		//cout << n - x << "-n-x x:" << x << " ";
		// 		v.push_back(x);
		// 		x = x + i;
		// 		i++;
		// 		//v.push_back(x);
		// 	}
		// 	else {
		// 		i = 1;
		// 		v.push_back(x);
		// 		x = x + i;
		// 		//v.push_back(x);
		// 	}
		// 	//v.push_back(x);
		// 	cnt++;
		// }
		int num = 1;
		int diff = 1;
		for (int i = 1; i <= k; i++) {
			cout << num << " ";
			if (num + diff <= n and n - num > k - i) {
				diff++;
				num += diff;
			}
			else {
				diff = 1;
				num += diff;
			}
		}
		// for (auto it : v) {
		// 	cout << it << " ";
		// }
		cout << endl;
	}
	return 0;

}