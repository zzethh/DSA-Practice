#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

// class compare {
// public:
// 	bool operator()(int a, int b) {
// 		return a > b;
// 	}
// };

set<int> sp;
set<int> sq;

bool solve(vector<int> &v, int n, vector<int> &p, vector<int> &q) {
	// forn(i, n) {
	// 	sp.insert(i + 1);
	// 	sq.insert(i + 1);
	// }
	forn(i, n) {
		auto f = sp.find(v[i]);
		auto x = sq.find(v[i]);
		if (f != sp.end()) {
			p[i] = v[i];
			sp.erase(f);
		}
		else if (x != sq.end()) {
			q[i] = v[i];
			sq.erase(x);
		}
		else return false;
	}

	forn(i, n) {
		if (p[i] != 0) {
			// auto it = sq.begin();
			// auto prev = sq.begin();
			// for (; it != sq.end() and * (it) <= p[i]; it++) {
			// 	prev = it;
			// }
			// if (*prev <= p[i]) {
			// 	q[i] = *prev;
			// 	sq.erase(prev);
			// }
			// else return false;

			auto itr = sq.upper_bound(p[i]);
			if (itr == sq.begin()) return false;
			itr = prev(itr);
			q[i] = *itr;
			sq.erase(itr);
		}
		else if (q[i] != 0) {
			// auto it = sp.begin();
			// auto prev = sp.begin();
			// for (; it != sp.end() and * (it) <= q[i]; it++) {
			// 	prev = it;
			// }
			// if (*prev <= q[i]) {
			// 	p[i] = *prev;
			// 	sp.erase(prev);
			// }
			// else return false;

			auto itr = sp.upper_bound(q[i]);
			if (itr == sp.begin()) return false;
			itr = prev(itr);
			p[i] = *itr;
			sp.erase(itr);
		}
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		forn(i, n) {
			cin >> v[i];
			sp.insert(i + 1);
			sq.insert(i + 1);
		}
		vector<int> p(n, 0);
		vector<int> q(n, 0);
		if (solve(v, n, p, q)) {
			cout << "YES" << endl;
			for (auto x : p) {
				cout << x << " ";
			}
			cout << endl;
			for (auto y : q) {
				cout << y << " ";
			}
		}
		else {
			cout << "NO";
		}

		cout << endl;
	}

	return 0;
}