#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

//never use zero based indexing
int sum(vector<int> &bit, int i) {
	int ans = 0;
	for (; i > 0; i -= (i & -i)) {
		ans += bit[i];
	}
	return ans;
}

void update(vector<int> &bit, int i , int val) {
	for (; i < bit.size(); i += (i & (-i))) {
		bit[i] += val;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> bit(n + 1);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(bit, i, a[i]);
	}
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << sum(bit, r) - sum(bit, l - 1) << endl;
		}
		else {
			int i, val;
			cin >> i >> val;
			update(bit, i, val - a[i]);
			a[i] = val;
		}
	}
}
// Driver code
int main()
{
	solve();
	return 0;
}

