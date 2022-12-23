#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		char ch;
		int maxi = INT_MIN;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ch;
			maxi = max(maxi, ch - 'a');
		}
		cout << maxi + 1 << endl;

	}

	return 0;
}
