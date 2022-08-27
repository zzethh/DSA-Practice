#include<bits/stdc++.h>
using namespace std;





int main() {

	vector<vector<int>> v = {
		{1, 3, 15},
		{2, 4, 6},
		{0, 9, 10, 11}
	};

	priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	for (int i = 0; i < v.size(); i++) {
		pq.push({v[i][0], 0, i});
	}

	while (!pq.empty()) {
		cout << pq.top()[0] << endl;
		int nextArray = pq.top()[2];
		int nextelement = pq.top()[1] + 1;
		pq.pop();
		if (nextelement < v[nextArray].size()) {
			pq.push({v[nextArray][nextelement], nextelement, nextArray});
		}
	}


	return 0;
}

