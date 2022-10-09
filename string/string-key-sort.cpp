#include<bits/stdc++.h>
using namespace std;


/*
3
92 022
82 12
77 13
2 true numeric
*/

string extractKey(string str, int key) {
	char* token = strtok((char*)str.c_str(), " ");
	char* ans;
	while (token != NULL) {
		if (key == 1) ans = token;
		token = strtok(NULL, " ");
		key--;
	}

	return (string)ans;
}

int convertToInt(string s) {
	int ans = 0;
	int p = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans = ans + ((s[i] - '0') * p);
		p = p * 10;
	}
	return ans;
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return (key1) < (key2);
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return convertToInt(key1) < convertToInt(key2);
}

int main() {
	int n;
	cin >> n;
	cin.get();
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		v.push_back(temp);
	}

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;


	vector<pair<string, string>> vp;

	for (int i = 0; i < v.size(); i++) {
		vp.push_back({v[i], extractKey(v[i], key)});
	}

	if (ordering == "numeric") sort(vp.begin(), vp.end(), numericCompare);
	else sort(vp.begin(), vp.end(), lexicoCompare);

	if (reversal == "true") reverse(vp.begin(), vp.end());

	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].first << endl;
	}

	return 0;
}

