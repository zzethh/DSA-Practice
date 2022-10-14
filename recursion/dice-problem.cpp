#include<bits/stdc++.h>
using namespace std;

void dice(int target, string output) {
	if (target == 0) {
		cout << output << endl;
	}

	for (int i = 1; i <= 6; i++) {
		if (target - i >= 0) {
			dice(target - i, output + to_string(i));
		}
	}
}

int main() {
	string ans = "";
	dice(4, ans);
	return 0;
}