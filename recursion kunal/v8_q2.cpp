#include<bits/stdc++.h>
using namespace std;

void permutation(string s, string output, int i) {
	if (s[i] == '\0') {
		cout << output << " ";
		return;
	}

	for (int j = 0; j <= output.length(); j++) {
		permutation(s, output.substr(0, j) + s[i] + output.substr(j, output.length()), i + 1);
	}
}

vector<string> permutation2(string s, string output, int i) {
	vector<string> v;

	if (s[i] == '\0') {
		v.push_back(output);
		return v;
	}

	for (int j = 0; j <= output.length(); j++) {
		vector<string> b[10];
		b[i] = permutation2(s, output.substr(0, j) + s[i] + output.substr(j, output.length()), i + 1);
		v.insert(v.end(), b[i].begin(), b[i].end());
	}
	return v;
}

int main() {
	string s;
	cin >> s;
	string output;
	vector<string> v = permutation2(s, output, 0);
	for (auto x : v) {
		cout << x << " ";
	}
	return 0;
}