#include<bits/stdc++.h>
using namespace std;

string skipAcharacter(string s, char c, int i) {
	if (s[i] == '\0') {
		return "";
	}

	if (s[i] != c) {
		return s[i] + skipAcharacter(s, c, i + 1);
	}

	else return skipAcharacter(s, c, i + 1);

}

int main() {
	string s = "baccad";
	char c = 'a';
	int i = 0;
	//skipAcharacter(s, c, i);
	cout << skipAcharacter(s, c, i);

	return 0;
}

