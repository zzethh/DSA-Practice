#include<bits/stdc++.h>
using namespace std;


int countingPath(int r, int c) {
	if (r == 1 or c == 1) {
		return 1;
	}
	int cnt = 0;
	cnt += countingPath(r - 1, c) + countingPath(r, c - 1);
	return cnt;

}


int main() {
	cout << countingPath(3, 3);
	return 0;
}