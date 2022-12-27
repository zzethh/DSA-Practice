#include<bits/stdc++.h>
using namespace std;


using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

void reverse(vector<vector<int>> &m) {
	for (int i = 0; i < m.size(); i++) {
		int x = 0;
		int y = m[0].size() - 1;
		while (x < y) {
			swap(m[i][x], m[i][y]);
			x++;
			y--;
		}
	}
}

void transpose(vector<vector<int>> &m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[0].size(); j++) {
			if (i > j) {
				swap(m[i][j], m[j][i]);
			}
		}
	}
}

bool isBeautiful(vector<vector<int>> &m) {
	if (m[0][0] < m[0][1] and m[1][0] < m[1][1] and m[0][0] < m[1][0] and m[0][1] < m[1][1]) {
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<vector<int>> a(2, vector<int>(2, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> a[i][j];
			}
		}
		int cnt = 0;
		while (!isBeautiful(a)) {
			if (cnt >= 4) {
				cout << "NO";
				break;
			}
			transpose(a);
			reverse(a);
			cnt++;
		}
		if (cnt < 4) cout << "YES";
		cout << endl;
	}
	return 0;

}