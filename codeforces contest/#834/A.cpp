#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

bool issubtr(string t, string s) {
	int tl = t.length();
	int sl = s.length();
	for (int i = 0; i < tl - sl + 1; i++) {
		if (t.substr(i, sl) == s) return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string t = "";
		for (int i = 0; i <= s.length() / 3 + 1; i++) {
			t = t + "Yes";
		}
		if (issubtr(t, s)) cout << "YES";
		else cout << "NO";

		cout << endl;
	}


	return 0;
}