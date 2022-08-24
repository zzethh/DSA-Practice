#include<bits/stdc++.h>
using namespace std;


//O(k+(n-k)logk)

//input
// 5
// 3
// C1 1 1
// C2 2 1
// C3 3 2
// C4 0 1
// C5 2 3

class Car {
public:
	string name;
	int x;
	int y;

	Car(string name, int x, int y) {
		this->name = name;
		this->x = x;
		this->y = y;
	}

	int distance() {
		return x * x  + y * y;
	}

	void show() {
		cout << name << " " << x << " " << y;
	}
};

void printvector(vector<Car> v) {
	for (auto car : v) {
		car.show();
		cout << endl;
	}
}

class carsCompare {
public:
	bool operator()(Car a, Car b) {
		if (a.distance() < b.distance()) {
			return true;
		}
	}
};



int main() {

	vector<Car> cars;
	int n;
	int k;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		string name;
		int x, y;
		cin >> name >> x >> y;
		Car car(name, x, y);
		cars.push_back(car);
	}


	priority_queue<Car, vector<Car>, carsCompare> pq(cars.begin(), cars.begin() + k);
	for (int i = k; i < n; i++) {
		auto car = cars[i];
		auto top = pq.top();
		if (top.distance() > car.distance()) {
			pq.pop();
			pq.push(cars[k]);
		}
	}


	while (!pq.empty()) {
		auto attop = pq.top();
		attop.show();
		cout << endl;
		pq.pop();
	}





	return 0;
}

