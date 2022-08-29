#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAttail(node* &head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}

void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}

void insertAthead(node* &head, int val) {
	node* n = new node(val);
	n->next = head;
	head = n;
}

// bool search(node* head, int key) {
// 	node* temp = head;
// 	while (temp != NULL) {
// 		if (temp->data == key) {
// 			return true;
// 		}
// 		temp = temp->next;
// 	}
// 	return false;
// }

// void insertInMiddle(node* &head, int data, int pos) {
// 	if (pos == 0) {
// 		insertAthead(head, data);
// 		return;
// 	}
// 	int cnt = 0;
// 	node* temp = head;
// 	while (temp != NULL && cnt != pos - 1) {
// 		temp = temp->next;
// 		cnt++;
// 	}
// 	node *n = new node(data);
// 	n->next = temp->next;
// 	temp->next = n;
// }

// void deleteAthead(node* &head) {
// 	node* todelete = head;
// 	head = head->next;

// 	delete todelete;
// }

// void deletion(node* &head, int val) {
// 	if (head == NULL) {
// 		return;
// 	}

// 	if (head->next == NULL) {
// 		deleteAthead(head);
// 	}

// 	node* temp = head;
// 	while (temp->next->data != val) {
// 		temp = temp->next;
// 	}
// 	node* todelete = temp->next;
// 	temp->next = temp->next->next;
// 	delete todelete;
// }

bool detectCycle(node* head) {
	node* slow = head;
	node* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}

void removeCycle(node* head) {
	node* slow = head;
	node* fast = head;
	do {
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	fast = head;
	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	slow->next = NULL;
}

int main() {
	node* head = NULL;
	insertAthead(head, 1);
	insertAthead(head, 7);
	insertAthead(head, 8);
	insertAthead(head, 0);
	insertAthead(head, 99);

	display(head);

	node* x = mergeSort(head);
	display(x);




	return 0;
}

