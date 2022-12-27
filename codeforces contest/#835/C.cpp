#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v[i] = temp;
		}
		vector<int> x = v;
		sort(v.begin(), v.end(), greater<int>());
		for (int i = 0; i < n; i++) {
			if (x[i] == v[0]) {
				cout << x[i] - v[1] << " ";
			}
			else {
				cout << x[i] - v[0] << " ";
			}
		}
		cout << endl;

	}

	return 0;
}