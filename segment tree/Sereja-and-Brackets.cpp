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
	vector<int> seg;
	Tree(int n) {
		seg.resize(4 * n + 1);
	}
	void build(int ind, int low, int high, vector<int> arr) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r) {
		//no overlap
		if (r < low or high < l) return INT_MAX;
		//complete overlap
		if (low >= l and high <= r) return seg[ind];

		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}
		int mid = (low + high) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};

void solve1() {
	// int n;
	// cin >> n;
	// vector<int> arr(n);
	// for (int i = 0; i < n; i++) cin >> arr[i];
	// vector<int> seg(4 * n);
	// build(0, 0, n - 1, arr, seg);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	int type;
	// 	cin >> type;
	// 	if (type == 1) {
	// 		int l, r;
	// 		cin >> l >> r;
	// 		cout << query(0, 0, n - 1, l, r, seg) << endl;
	// 	}
	// 	else {
	// 		int i, val;
	// 		cin >> i >> val;
	// 		update(0, 0, n - 1, i, val, seg);
	// 		arr[i] = val;
	// 	}

	// }
}

void solve2() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	Tree st1(n);
	st1.build(0, 0, n - 1, arr);

	int n2;
	cin >> n2;
	vector<int> arr2(n2);
	for (int i = 0; i < n2; i++) cin >> arr2[i];
	Tree st2(n2);
	st2.build(0, 0, n2 - 1, arr2);

	int t;
	cin >> t;
	while (t--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			int min1 = st1.query(0, 0, n - 1, l1, r1);
			int min2 = st2.query(0, 0, n2 - 1, l2, r2);
			cout << min(min1, min2) << endl;
		}
		else {
			int arrno, i, val;
			cin >> arrno >> i >> val;
			if (arrno == 1) {
				st1.update(0, 0, n - 1, i, val);
				arr[i] = val;
			}
			else {
				st2.update(0, 0, n2 - 1, i, val);
				arr2[i] = val;
			}
		}

	}
}

// void build(int ind, int low, int high, int arr[], int seg[], int orr) {
// 	if (low == high) {
// 		seg[ind] = arr[low];
// 		return;
// 	}
// 	int mid = (low + high) / 2;
// 	build(2 * ind + 1, low, mid, arr, seg, !orr);
// 	build(2 * ind + 2, mid + 1, high, arr, seg, !orr);
// 	if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
// 	else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
// }
// void update(int ind, int low, int high, int seg[], int orr, int i, int val) {
// 	if (low == high) {
// 		seg[ind] = val;
// 		return;
// 	}
// 	int mid = (low + high) / 2;
// 	if (i <= mid) update(2 * ind + 1, low, mid, seg, !orr, i, val);
// 	else update(2 * ind + 2, mid + 1, high, seg, !orr, i, val);
// 	if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
// 	else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
// }
// void solve3() {
// 	int n, q;
// 	cin >> n >> q;
// 	int el = pow(2, n);
// 	int arr[el];
// 	for (int i = 0; i < el; i++) {
// 		cin >> arr[i];
// 	}
// 	int seg[4 * el];
// 	if (n % 2 == 0) build(0, 0, el - 1, arr, seg, 0);
// 	else build(0, 0, el - 1, arr, seg, 1);

// 	while (q--) {
// 		int i, val;
// 		cin >> i >> val;
// 		i--;
// 		if (n % 2 == 0) update(0, 0, el - 1, seg, 0, i, val);
// 		else update(0, 0, el - 1, seg, 1, i, val);
// 		cout << seg[0] << endl;
// 	}
// }

class info {
public:
	int open, close, full;
	info() {
		open = 0;
		close = 0;
		full = 0;
	}
	info(int o, int c, int f) {
		open = o;
		close = c;
		full = f;
	}
};
info merge(info left, info right) {
	info ans;
	ans.full = left.full + right.full + min(left.open, right.close);
	ans.open = left.open + right.open - min(left.open, right.close);
	ans.close = left.close + right.close - min(left.open, right.close);
	return ans;
}
void build(int ind, int low, int high, string &s, info seg[]) {
	if (low == high) {
		seg[ind] = info(s[low] == '(', s[low] == ')', 0);
		return;
	}
	int mid = (low + high) / 2;
	build(2 * ind + 1, low, mid, s, seg);
	build(2 * ind + 2, mid + 1, high, s, seg);
	seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
}

info query(int ind, int low, int high, int l, int r, info seg[]) {
	//no overlap
	if (r < low or high < l) return info();
	//complete overlap
	if (low >= l and high <= r) return seg[ind];

	int mid = (low + high) / 2;
	info left = query(2 * ind + 1, low, mid, l, r, seg);
	info right = query(2 * ind + 2, mid + 1, high, l, r, seg);
	return merge(left, right);
}
void solve4() {
	string s;
	cin >> s;
	int n = s.length();
	info seg[4 * n];
	build(0, 0, n - 1, s, seg);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		//cout << query() << endl;
		info ans = query(0, 0, n - 1, l, r, seg);
		cout << ans.full * 2 << endl;
	}
}
// Driver code
int main()
{
	solve4();
	return 0;
}

