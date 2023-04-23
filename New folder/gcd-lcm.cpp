#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
// Driver code
int main()
{
	cout << gcd(4, 5);




	return 0;
}

