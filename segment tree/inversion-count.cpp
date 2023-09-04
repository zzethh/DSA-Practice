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
/*
Question 2 find inversion count of array
Input :
N
N elemnts of array

Example :
5
8 4 9 2 8
Output :
5

Large input :
5
100000000 10000 10000000000 10 100000000
Output :
5
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int bit[N];

void update(int i, int x) {
	for (; i < N; i += (i & -i))
		bit[i] += x;
}

int sum(int i) {
	int ans = 0;
	for (; i > 0; i -= (i & -i))
		ans += bit[i];
	return ans;
}

int main() {
	int n;
	cin >> n;
	long long a[n + 10];
	map<long long, int> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mp[a[i]];
	}


	// compression of numbers for the case where a[i] > 10 ^ 6
	int ptr = 1;
	for (auto &pr : mp) {
		pr.second = ptr++;
	}

	for (int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}

	// Finding Inversion count


	int inversion_ct = 0;
	for (int i = 1; i <= n; ++i) {
		inversion_ct += (sum(N - 5) - sum(a[i]));
		update(a[i], 1);
	}

	cout << inversion_ct << endl;


}
// Driver code
int main()
{
	solve();
	return 0;
}

