#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int l = 0;
		int r = n - 1;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}

		int cnt = 0;

		while (l < r) {
			if (a[l + 1] <= a[l] and a[r - 1] <= a[r]) {
				l++;
				r--;
			}
			else if (a[r - 1] <= a[r]) {
				r--;
			}
			else if (a[l + 1] <= a[l]) {
				l++;
			}
			else break;
		}

		if (l == r or abs(l - r) == 1) {
			cout << "YES";
		}
		else cout << "NO";

		cout << endl;

	}

	return 0;
}

