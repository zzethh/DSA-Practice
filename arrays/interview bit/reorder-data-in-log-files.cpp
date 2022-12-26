#include<bits/stdc++.h>
using namespace std;
#define int long long int


vector<string> log(vector<string> &A) {
	vector<pair<string, int>> alp;
	vector<string> num;
	for (int i = 0; i < A.size(); i++) {
		int j = 0;
		char x = A[i][j];
		string iden = "";
		while (A[i][j] != '-') {
			iden = iden + A[i][j];
			j++;
		}
		j++;
		string s = "";
		if (isalpha(A[i][j])) {
			while (A[i][j] != '\0') {
				//if (A[i][j] != '-')
				s = s + A[i][j];
				j++;
			}
			s = s + iden;
			alp.push_back({s, i});
		}
		else if (isdigit(A[i][j])) {
			num.push_back(A[i]);
		}
	}
	sort(alp.begin(), alp.end());
	vector<string> ans;
	for (auto x : alp) {
		ans.push_back(A[x.second]);
	}
	for (auto x : num) {
		ans.push_back(x);
	}
	return ans;
}

signed main() {
	vector<string> v = {"qv4-tbojcv-yd", "uh9-lmtdpiunu", "ta9-5-3-5-5-1", "hn2-yawf-jw-zkw", "nc7-hdly-hrht", "ja7-6-5-7-0-4", "ld1-le-cmt-t-z", "hu2-wfkpj-jv", "iy0-hujr-wmrg-ca", "ia7-y-l-bnaz", "nr1-7-1-7-0-4", "gx0-sm-by-wd-ea"};
	vector<string> ans = log(v);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;

}


vector<string> Solution::reorderLogs(vector<string> &A) {
	vector<pair<string, int>> alp;
	vector<string> num;
	set<pair<string, int>> se;
	for (int i = 0; i < A.size(); i++) {
		int j = 0;
		char x = A[i][j];
		string iden = "";
		while (A[i][j] != '-') {
			iden = iden + A[i][j];
			j++;
		}
		j++;
		string s = "";
		s = s + A[i].substr(j, A[i].length() - iden.length() - 1) + '-' + iden;
		if (isalpha(A[i][j])) {
			se.insert({s, i});
		}
		else if (isdigit(A[i][j])) {
			num.push_back(A[i]);
		}
	}
	//sort(alp.begin(), alp.end());
	vector<string> ans;
	for (auto x : se) {
		ans.push_back(A[x.second]);
	}
	for (auto x : num) {
		ans.push_back(x);
	}
	return ans;
}
