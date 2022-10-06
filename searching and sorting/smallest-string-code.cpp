#include<bits/stdc++.h>
using namespace std;

bool compare(string x, string y) {
	return x + y < y + x;
}

int main() {
	vector<string> s = {"a", "ab", "aba"};
	int n = 3;
	sort(s.begin(), s.end(), compare);
	for (auto x : s) {
		cout << x;
	}
	return 0;
}

