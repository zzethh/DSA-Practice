#include<bits/stdc++.h>
using namespace std;

int sparseSearch(vector<string> v, string k) {
	int s = 0;
	int e = v.size() - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (v[mid] == "") {
			int i = mid - 1;
			int j = mid + 1;
			while (v[i] != "" and v[j] != "") {
				i--;
				j++;
			}
			if (v[i] != "") {
				mid = i;
			}
			else mid = j;
		}
		if (v[mid] == k) {
			return mid;
		}
		else if (v[mid] > k) {
			e = mid - 1;
		}
		else s = mid + 1;
	}

	return -1;
}

int main() {
	vector<string> s = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
	int n = 3;
	cout << sparseSearch(s, "bat");
	return 0;
}

