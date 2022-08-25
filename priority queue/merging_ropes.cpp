#include<bits/stdc++.h>
using namespace std;





int main() {

	vector<int> ropes = {4, 3, 2, 6};
	int n = ropes.size();
	priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.begin() + n);
	int sum = 0;
	while (pq.size() > 1) {
		int l1 = pq.top();
		pq.pop();
		int l2 = pq.top();
		pq.pop();

		sum = sum + l1 + l2;
		pq.push(l1 + l2);
	}
	cout << sum;

	return 0;
}

