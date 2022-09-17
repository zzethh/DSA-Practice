#include<bits/stdc++.h>
using namespace std;

class point {
public:
	int x;
	int y;

	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class compare {
public:
	bool operator()(point a, point b) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
};

int count_rectangle(vector<point> v) {
	map<point, int, compare> m;

	for (auto x : v) {
		m[x]++;
	}
	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			point p1 = v[i];
			point p2 = v[j];
			if (p1.x == p2.x or p1.y == p2.y) {
				continue;
			}
			point p3(p1.x, p2.y);
			point p4(p2.x, p1.y);
			if (m[p3] and m[p4]) {
				ans = ans + 1;
			}
		}
	}
	return ans / 2;
}

int main() {
	int n;
	cin >> n;
	int x, y;
	vector<point> v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point p(x, y);
		v.push_back(p);
	}
	cout << count_rectangle(v);
	return 0;
}

