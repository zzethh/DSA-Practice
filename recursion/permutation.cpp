#include<bits/stdc++.h>
using namespace std;

void permute(string v, string ans, int k) {
	if (v[k] == '\0') {
		cout << ans << endl;
		return;
	}

	for (int i = 0; i <= ans.length(); i++) {
		permute(v, v.substr(0, i) + v[k] + v.substr(i, ans.length() - i), k + 1);
	}
}



int main() {
	string s = "abc";
	string ans = "";
	permute(s, ans, 0);

	return 0;
}