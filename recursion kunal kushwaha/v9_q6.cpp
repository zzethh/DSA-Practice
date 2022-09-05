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

vector<string> dice2(int target, string output) {
	vector<string> v;

	if (target == 0) {
		v.push_back(output);
		return v;
	}

	for (int i = 1; i <= 6 && i <= target; i++) {
		vector<string> b = dice2(target - i, output + to_string(i));
		v.insert(v.end(), b.begin(), b.end());
	}
	return v;
}

int dice3(int target, string output) {
	if (target == 0) {
		return 1;
	}
	int cnt = 0;

	for (int i = 1; i <= 6 && i <= target; i++) {
		cnt = cnt + dice3(target - i, output + to_string(i));
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	string output;
	//dice(t, output);

	// vector<string> v = dice2(t, output);
	// for (auto x : v) {
	// 	cout << x << " ";
	// }
	// cout << endl;

	cout << dice3(t, output);
	return 0;
}