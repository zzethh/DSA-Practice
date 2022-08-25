#include<bits/stdc++.h>
using namespace std;

void phonekeypad(string s, string output, int i) {
	if (s[i] == '\0') {
		cout << output << " ";
		return;
	}

	int digit = s[i] - '0';
	for (int j = (digit - 1) * 3; j < (digit) * 3; j++) {
		if (j < 26) {
			char c = 'a' + j;
			phonekeypad(s, output + c, i + 1);
		}
	}

}

vector<string> phonekeypad2(string s, string output, int i) {

	vector<string> v;

	if (s[i] == '\0') {
		v.push_back(output);
		return v;
	}

	int digit = s[i] - '0';
	for (int j = (digit - 1) * 3; j < (digit) * 3; j++) {
		if (j < 26) {
			char c = 'a' + j;
			vector<string> x;
			x = phonekeypad2(s, output + c, i + 1);
			v.insert(v.end(), x.begin(), x.end());
		}
	}
	return v;

}

int phonekeypad3(string s, string output, int i) {
	if (s[i] == '\0') {
		return 1;
	}

	int cnt = 0;

	int digit = s[i] - '0';
	for (int j = (digit - 1) * 3; j < (digit) * 3; j++) {
		if (j < 26) {
			char c = 'a' + j;
			cnt = cnt + phonekeypad3(s, output + c, i + 1);
		}
	}

	return cnt;

}

int main() {
	string s;
	cin >> s;
	string output;

	cout << phonekeypad3(s, output, 0);

	// vector<string> v = phonekeypad2(s, output, 0);
	// for (auto x : v) {
	// 	cout << x << "->";
	// }
	return 0;
}