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

vector<string> subseq2(string input, string output, int i, vector<string> v) {
	//static int i = 0;
	if (input[i] == '\0') {
		v.push_back(output);
		return v;
	}
	vector<string> first = subseq2(input, output + input[i], i + 1, v);
	vector<string> second = subseq2(input, output, i + 1, v);

	string ascii = to_string(input[i] + 0);
	vector<string> third = subseq2(input, output + ascii, i + 1, v);

	first.insert(end(first), begin(second), end(second));
	first.insert(end(first), begin(third), end(third));

	return first;
}

int main() {
	string s;
	cin >> s;
	string output;
	vector<string> v;
	vector<string> o = subseq2(s, output, 0, v);
	for (auto x : o) {
		cout << x << " ";
	}

	return 0;
}