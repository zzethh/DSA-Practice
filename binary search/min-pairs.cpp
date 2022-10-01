#include<bits/stdc++.h>
using namespace std;

pair<int, int> minpair(vector<int> a, vector<int> b) {
	pair<int, int> p;
	int diff = INT_MAX;
	sort(b.begin(), b.end());
	for (int x : a) {
		int y = lower_bound(b.begin(), b.end(), x) - b.begin();

		if (y >= 1 and x - b[y - 1] < diff) {
			diff = x - b[y - 1];
			p.first = x;
			p.second = b[y - 1];
		}

		if (y != b.size() and b[y] - x < diff) {
			diff = b[y] - x;
			p.first = x;
			p.second = b[y - 1];
		}
	}
	return p;
}


pair<int, int> minpair2(vector<int> a, vector<int> b) {
	pair<int, int> p;
	int mini = INT_MAX;
	sort(b.begin(), b.end());
	for (int x : a) {
		int y = lower_bound(b.begin(), b.end(), x) - b.begin();
		int diff = INT_MAX;
		if (y != b.size()) diff = abs(x - b[y]);
		if (y >= 1) {
			int diff2 = abs(x - b[y - 1]);
			if (diff2 < diff) {
				diff = diff2;
				y = y - 1;
			}
		}
		if (diff < mini) {
			p.first = x;
			p.second = b[y];
			mini = diff;
		}
	}
	return p;
}


int main() {
	vector<int> a1 = { -1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	pair<int, int> p;
	p = minpair(a1, a2);
	cout << p.first << " " << p.second;
	return 0;
}




int main() {
	vector<int> a1 = { -1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	pair<int, int> p;
	p = minpair(a1, a2);
	cout << p.first << " " << p.second;
	return 0;
}

