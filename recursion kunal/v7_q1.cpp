#include<bits/stdc++.h>
using namespace std;

void skipa(string s, string &o) {
	static int i = 0;
	if (i == s.length()) {
		return;
	}
	if (s[i] == 'a') {
		i++;
		skipa(s, o);
	} else {
		o = o + s[i];
		i++;
		skipa(s, o);
	}

}

string skipa2(string s, int i) {

	if (i == s.length()) {
		return "";
	}
	if (s[i] == 'a') {
		return skipa2(s, i + 1);
	} else {
		string m = skipa2(s, i + 1);
		m = s[i] + m;
		return m;
	}

}


int main() {
	string s;
	string o = "";
	cin >> s;
	cout << skipa2(s, 0);
	//cout << o << endl;

	return 0;
}