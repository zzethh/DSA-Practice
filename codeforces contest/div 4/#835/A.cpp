#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		set<int> s;
		for (int i = 0; i < 3; i++) {
			int x;
			cin >> x;
			s.insert(x);
		}
		cout << *(++s.begin()) << endl;
	}

	return 0;
}