#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<int> b, int i, int j, float &lose, float &win, float &equal, float &outcome) {
	if (i == 6) {
		return;
	}
	if (j == 6) {
		return;
	}
	if (a[i] < b[j]) lose++;
	if (a[i] == b[i]) equal++;
	if (a[i] > b[j]) {
		//cout << a[i] << "," << b[j] << endl;
		win++;
	}
	outcome++;
	cout << a[i] << "," << b[j] << endl;
	helper(a, b, i, j + 1, lose, win, equal, outcome);
	helper(a, b, i + 1, j, lose, win, equal, outcome);
}

float helper2(vector<int> a, vector<int> b) {
	float awin = 0;
	float bwin = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] > b[j]) {
				awin++;
			}
			else if (a[i] < b[j]) {
				bwin++;
			}
		}
	}
	cout << awin << " " << bwin << " ";
	awin = awin / 36.0;
	bwin = bwin / 36.0;
	float ainv = 1.0 - awin;
	float binv = 1.0 - bwin;
	cout << awin << " " << bwin << " " << ainv << " " << binv << " ";
	float ans = (awin) / (1 - (ainv * binv));
	return ans;
}

int main() {
	float win = 0.0;
	float lose = 0.0;
	float equal = 0.0;
	float outcome = 0.0;
	vector<int> bob = {1, 1, 1, 1, 1, 5};
	vector<int> jack = {4, 4, 4, 4, 4, 4};
	cout << helper2(bob, jack);
	return 0;
}

