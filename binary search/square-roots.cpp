#include<bits/stdc++.h>
using namespace std;

float findingroots(int k, int p) {
	int s = 0;
	int e = k;
	float ans = 0;
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

	float inc = 0.1;

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
	int target = 25;
	int p = 4;
	cout << findingroots(target, p);
	return 0;
}

