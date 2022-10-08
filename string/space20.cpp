#include<bits/stdc++.h>
using namespace std;

void space20(char ch[1000]) {
	int space = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == ' ') {
			space++;
		}
	}

	space = space * 2 + strlen(ch);
	ch[space] = '\0';

	for (int i = strlen(ch) - 1; i >= 0; i--) {
		if (ch[i] != ' ') {
			ch[space - 1] = ch[i];
			space--;
		}
		else {
			ch[space - 1] = '0';
			ch[space - 2] = '2';
			ch[space - 3] = '%';
			space = space - 3;
		}
	}
}

int main() {
	char ch[1000] = "hello world,  how are you?";
	space20(ch);
	cout << ch;
	return 0;
}

