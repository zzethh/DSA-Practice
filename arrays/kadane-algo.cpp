#include<bits/stdc++.h>
using namespace std;

pair<int, int> kadaneAlgo(vector<int> v) {
	int maxSum = v[0];
	int currentSum = v[0];
	for (int i = 1; i < v.size(); i++) {

		if (currentSum >= 0) {
			currentSum += v[i];
		}

		else currentSum = arr[i];

		if (currentSum > maxSum) {
			currentSum = maxSum;
		}
	}

	return maxSum;
}

int main() {
	vector<int> arr = {5, 2, 9, 1, 100};
	cout << kadaneAlgo(arr);
	return 0;
}

