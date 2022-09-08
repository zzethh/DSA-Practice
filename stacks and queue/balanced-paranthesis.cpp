#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str) {
	stack<char> s;
	for (char c : str) {
		switch (c) {
		case '[': s.push(c);
			break;
		case '(': s.push(c);
			break;
		case '{': s.push(c);
			break;
		case ']': if (!s.empty() and s.top() == '[') {
				s.pop();
			} else {
				return false;
			}
			break;

		case ')': if (!s.empty() and s.top() == '(') {
				s.pop();
			} else {
				return false;
			}
			break;

		case '}': if (!s.empty() and s.top() == '{') {
				s.pop();
			} else {
				return false;
			} break;

		}
	}
	return true;
}
int main() {
	string str;
	getline(cin, str);
	cout << isBalanced(str);

	return 0;
}

