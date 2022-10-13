#include<bits/stdc++.h>
using namespace std;

void subset(string s, vector<string> &v, string ans, int i) {
	if (s[i] == '\0') {
		v.push_back(ans);
		//cout << ans;
		return;
	}

	//char c = s[i];
	subset(s, v, ans + s[i], i + 1);
	subset(s, v, ans, i + 1);
}

int main() {
	string s = "abc";
	int i = 0;
	string ans = "";
	vector<string> v;
	subset(s, v, ans, i);
	for (auto x : v) {
		cout << x << " ";
	}

	return 0;
}

