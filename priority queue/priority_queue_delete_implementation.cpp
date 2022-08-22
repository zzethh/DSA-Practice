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

	void deleteMin() {
		swap(pq[0], pq[pq.size() - 1]);
		pq.pop_back();
		int parent = 0;
		while (true) {

			int min = parent;;
			int lchild = 2 * parent + 1;
			int rchild = 2 * parent + 2;

			if (lchild < pq.size() && pq[lchild] < pq[min]) {
				min = lchild;
			}
			if (rchild < pq.size() && pq[rchild] < pq[min]) {
				min = rchild;
			}
			if (min == parent) {
				break;
			}
			swap(pq[parent], pq[min]);
			parent = min;
		}
	}

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
	cout << endl;
	pq.deleteMin();
	pq.print();
	cout << endl;
	pq.deleteMin();
	pq.print();


	return 0;
}

