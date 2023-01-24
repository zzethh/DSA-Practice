#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long


string solve(string A) {
	int n = A.length() - 1;
	int len = 0;
	string ans = "";

	int s = 0;
	while (!isalpha(A[s])) {
		s++;
	}

	int e = n;
	while (!isalpha(A[e])) {
		e--;
	}

	for (int i = e; i >= s;) {
		len = 0;
		while (A[i] != ' ' and i >= s) {
			len++;
			i--;
		}
		ans += A.substr(i + 1, len) + ' ';
		while (!isalpha(A[i]) and i >= s) {
			i--;
		}
	}
	//// ans=trail+ans+lead;
	return ans;

}

int main()
{	string s = "hello   sup   world";
	cout << solve(s);
	return 0;
}