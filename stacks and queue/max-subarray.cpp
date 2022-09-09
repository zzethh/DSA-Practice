#include<bits/stdc++.h>
using namespace std;

void maxSubArrayK(vector<int> a, int k) {
	deque<int> q(k);
	int i;
	for (i = 0; i < k; i++) {
		while (!q.empty() and a[i] > a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}

	for (; i < a.size(); i++) {
		cout << q.front();
		while (!q.empty() and a[q.front] <= i - k) {
			q.pop_front();
		}
		while (!q.empty() and a[i] >= a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
}

int main() {
	queue<char> q;


	return 0;
}

