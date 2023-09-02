#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long
class Tree {
public:
	vector<int> seg, lazy;
	Tree(int n) {
		seg.resize(4 * n + 1);
		lazy.resize(4 * n);
	}
	void build(int ind, int low, int high, vector<int> arr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}

	int query(int ind, int low, int high, int l, int r) {
		if (lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];
			if (low != high) {
				//propagate the lazy update downwars
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
		//no overlap
		if (r < low or high < l) return 0;
		//complete overlap
		if (low >= l and high <= r) return seg[ind];

		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}

	void update(int ind, int low, int high, int l, int r, int val) {
		if (lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind];
			if (low != high) {
				//propagate the lazy update downwars
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}
		//no overlap
		if (r < low or high < l) {
			return;
		}
		//complete overlap
		if (low >= l and high <= r) {
			seg[ind] += (high - low + 1) * val;
			if (low != high) {
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}
			return;
		}

		int mid = (low + high) / 2;
		update(2 * ind + 1, low, mid, l, r, val);
		update(2 * ind + 2, mid + 1, high, l, r, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	Tree t(n);
	t.build(0, 0, n - 1, arr);
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			cout << t.query(0, 0, n - 1, l, r) << endl;
		}
		else {
			int l, r, val;
			cin >> l >> r >> val;
			t.update(0, 0, n - 1, l, r, val);
		}
	}
}



// Driver code
int main()
{
	solve();
	return 0;
}

