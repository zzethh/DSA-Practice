#include<bits/stdc++.h>
using namespace std;

double findingroots(int k, int p) {
	int s = 0;
	int e = k;
	double ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid * mid == k) {
			return mid;;
		}
		else if (mid * mid < k) {
			ans = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	double inc = 0.1;

	for (int i = 1; i <= p; i++) {
		while (ans * ans <= k) {
			ans = ans + inc;
		}
		ans = ans - inc;
		inc = inc / 10.0;
	}

	return ans;
}


int main() {
	int target = 19;
	int p = 6;
	cout << findingroots(target, p) << endl;
	float x = 1.23456789;
	cout << x;
	return 0;
}

