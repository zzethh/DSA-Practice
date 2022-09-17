#include<bits/stdc++.h>
using namespace std;

vector<int> hashit(string s, int i, int j) {
	vector<int> freq(26, 0);

	for (int k = i; k <= j; k++) {
		char ch = s[k];
		freq[ch - 'a']++;
	}

	return freq;
}

int anagrams(string s) {
	map<vector<int>, int> m;
	for (int i = 0; i < s.length(); i++) {
		for (int j = i; j < s.length(); j++) {
			vector<int> h = hashit(s, i, j);
			m[h]++;
		}
	}

	int ans = 0;
	for (auto x : m) {
		int freq = x.second;
		if (freq >= 2) {
			ans = ans + (freq) * (freq - 1) / 2;
		}

	}
	return ans;
}


int main() {
	string s = "abcd";
	cout << anagrams(s);
	return 0;
}

