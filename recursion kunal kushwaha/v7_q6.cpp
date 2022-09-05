#include<bits/stdc++.h>
using namespace std;

void subseq(string input, string output, int i) {
	//static int i = 0;
	if (input[i] == '\0') {
		cout << output << endl;
		return;
	}
	subseq(input, output + input[i], i + 1);
	string ascii = to_string(input[i] + 0);
	subseq(input, output + ascii, i + 1);
	subseq(input, output, i + 1);
}



int main() {
	string s;
	cin >> s;
	string output;
	vector<string> v;
	// vector<string> o = subseq2(s, output, 0, v);
	// for (auto x : o) {
	// 	cout << x << " ";
	// }
	subseq(s, output, 0);


	char ch = 'a';
	cout << sizeof(ch + 0);
	return 0;
}