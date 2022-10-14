#include<bits/stdc++.h>
using namespace std;

void phonekey(string s, string ans, int i) {
	if (s[i] == '\0') {
		cout << ans << endl;
		return;
	}

	int digit = s[i] - '0';
	for (int j = (digit - 1) * 3; j < digit * 3; j++) {
		if (j < 26) {
			char c = 'a' + j;
			phonekey(s, ans + c, i + 1);
		}
	}

}

int main() {
	string s = "23";
	string ans = "";
	phonekey(s, ans, 0);
	return 0;
}