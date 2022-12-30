#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

bool ispermute(vector<int> v) {
	sort(v.begin(), v.end());
	forn(i, v.size()) {
		if (v[i] != i + 1) return false;
	}
	return true;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		set<int> s;
		vector<int> v;
		int n;
		cin >> n;
		int sum;
		cin >> sum;
		forn(i, n) {
			int x;
			cin >> x;
			v.push_back(x);
			s.insert(x);
		}
		int i = 1;
		while (sum > 0) {
			if (s.find(i) == s.end()) {
				v.push_back(i);
				sum = sum - i;
			}
			i++;
		}
		if (sum == 0 and ispermute(v)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}


	return 0;
}