#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

void solve(vector<int> v) {

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v;
		forn(i, n) {
			int x;
			cin >> x;
			v.pb(x);
		}
		int a = 0, b = 0, c = 0;
		forn (i, n) {
			if (v[i] != i + 1 and v[i] != n - i) {
				c++;
			}
			else if (v[i] != i + 1) {
				a++;
			}
			else if (v[i] != n - i) {
				b++;
			}
		}
		if (a + c <= b) cout << "First";
		else if (b + c < a) cout << "Second";
		else cout << "Tie";
		cout << endl;
	}


	return 0;

}


