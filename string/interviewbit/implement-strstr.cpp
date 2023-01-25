int Solution::strStr(const string A, const string B) {
	if (A == "" or B == "") return -1;
	vector<int> v;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == B[0]) {
			v.push_back(i);
		}
	}
	int n = B.length();
	bool flag = false;
	int idx;
	int ans;
	int re;
	for (int i = 0; i < v.size(); i++) {
		idx = v[i];
		ans = idx;
		int k = 0;
		while (A[idx] == B[k] and idx < A.length() and k < B.length()) {
			//cout << A[idx] << "^" << B[k];
			k++;
			idx++;
		}

		if (k == B.length()) {
			flag = true;
			re = ans;
			break;
		}
	}
	if (flag) return re;
	return -1;
}
