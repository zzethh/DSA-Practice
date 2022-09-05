#include<bits/stdc++.h>
using namespace std;

void subseq(string input, string output, int i) {
	//static int i = 0;
	if (input[i] == '\0') {
		cout << output << " ";
		return;
	}
	subseq(input, output + input[i], i + 1);
	subseq(input, output, i + 1);
}

int main() {
	string s;
	cin >> s;
	string output;
	subseq(s, output, 0);
	return 0;
}