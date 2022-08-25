#include<bits/stdc++.h>
using namespace std;


void dice(int target, string output) {
	if (target == 0) {
		cout << output << " ";
		return;
	}

	for (int i = 1; i <= 6 && i <= target; i++) {
		dice(target - i, output + to_string(i));
	}
}


int main() {
	int t;
	cin >> t;
	string output;
	dice(t, output);
	return 0;
}