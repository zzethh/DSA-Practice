#include<bits/stdc++.h>
using namespace std;

void phonekeypad(string s, string output, int i) {
	if (s[i] == '\0') {
		cout << output << " ";
		return;
	}

	int digit = s[i] - '0';
	for (int j = (digit - 1) * 3; j < (digit) * 3; j++) {
		char c = 'a' + j;
		phonekeypad(s, output + c, i + 1);
	}

}

int main() {
	string s;
	cin >> s;
	string output;
	phonekeypad(s, output, 0);
	return 0;
}