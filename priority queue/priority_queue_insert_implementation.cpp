#include<bits/stdc++.h>
using namespace std;

class priorityQueue {
	vector<int> pq;
public:
	priorityQueue() {

	};

	bool isEmpty() {
		return pq.size() == 0;
	};

	int getSize() {
		return pq.size();
	};

	int getMin() {
		return pq[0];
	};

	void insert(int element) {
		pq.push_back(element);
		int CI = pq.size() - 1;
		while (CI > 0) {
			int PI = (CI - 1) / 2;
			if (pq[CI] < pq[PI]) {
				swap(pq[CI], pq[PI]);
				CI = PI;
			} else {
				break;
			}
		}
	};

	void print() {
		for (auto v : pq) {
			cout << v << " ";
		}
	};
};

int main() {

	priorityQueue pq;
	pq.insert(100);
	pq.insert(10);
	pq.insert(15);
	pq.insert(1);
	pq.insert(4);
	pq.insert(17);
	pq.insert(21);
	pq.insert(67);

	pq.print();


	return 0;
}

