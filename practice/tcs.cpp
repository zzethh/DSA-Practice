#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long


int main()
{	string s;
	cin >> s;

	int t;
	cin >> t;
	while (t--) {
		int i, j;
		cin >> i >> j;
		vector<int> cheese;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c == '|') {
				cheese.push_back(i);
			}
		}

		int x = 0;
		int y = 0;
		for (int k = 0; k < cheese.size(); k++) {
			if (cheese[k] >= i) {
				x = cheese[k];
				break;
			}
		}
		for (int k = 0; k < cheese.size(); k++) {
			if (cheese[k] <= j) y = cheese[k];
			else break;
		}

		//cout << x << " " << y << " ";
		int cnt2 = 0;
		for (int k = x + 1; k < y; k++) {
			if (s[k] == '*') cnt2++;
		}

		if (x >= y) cout << 0 << endl;
		else cout << cnt2 << endl;

	}
	return 0;
}