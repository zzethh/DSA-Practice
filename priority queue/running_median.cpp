#include<bits/stdc++.h>
using namespace std;





int main() {

	vector<int> v = {10, 5, 2, 3, 0, 12, 18, 20, 22};
	priority_queue<int> max;
	priority_queue < int, vector<int>, greater<int>> min;
	max.push(v[0]);
	float med = max.top();
	for (int i = 1; i < v.size(); i++) {
		cout << med << endl;
		if (max.size() > min.size()) {
			if (v[i] < med) {
				min.push(max.top());
				max.pop();
				max.push(v[i]);
			} else {
				min.push(v[i]);
			}
			med = (max.top() + min.top()) / 2.0;
		} else if (max.size() < min.size()) {
			if (v[i] < med) {
				min.push(v[i]);
			} else {
				max.push(min.top());
				min.pop();
				min.push(v[i]);
			}
			med = (max.top() + min.top()) / 2.0;
		} else {
			if (v[i] < med) {
				max.push(v[i]);
				med = max.top();
			} else {
				min.push(v[i]);
				med = min.top();
			}
		}
	}

	cout << med;

	return 0;
}

