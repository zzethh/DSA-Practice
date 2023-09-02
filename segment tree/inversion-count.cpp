#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

const int N = 100;
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
	vector<int> bit(N);
	vector<int> a(n + 10);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//update(bit, a[i], 1);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += sum(bit, N - 5) - sum(bit, a[i]);
		update(bit, a[i], 1);
	}
	cout << cnt;
}
// Driver code
int main()
{
	solve();
	return 0;
}

