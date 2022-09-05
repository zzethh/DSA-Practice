#include<bits/stdc++.h>
using namespace std;

void permutation(string s, string output, int i) {
	if (s[i] == '\0') {
		cout << output << " ";
		return;
	}

	for (int j = 0; j <= output.length(); j++) {
		permutation(s, output.substr(0, j) + s[i] + output.substr(j, output.length() - j), i + 1);
	}
}

int main() {
	string s;
	cin >> s;
	string output;
	permutation(s, output, 0);
	return 0;
}