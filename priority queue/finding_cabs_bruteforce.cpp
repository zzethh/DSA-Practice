#include<bits/stdc++.h>
using namespace std;

//O(nlogn)
//building a heap cost O(n), insrtion cost O(logn)

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
		return sqrt(x * x + y * y);
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

bool carCompare(Car A, Car B) {
	if (A.distance() > B.distance()) {
		return true;
	}
}


int main() {

	vector<Car> cars;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int x, y;
		cin >> name >> x >> y;
		Car car(name, x, y);
		cars.push_back(car);
	}

	sort(cars.begin(), cars.end(), carCompare);
	printvector(cars);





	return 0;
}

