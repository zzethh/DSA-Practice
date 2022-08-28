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

void insertAthead(node* &head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		n->next = n;
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
	head = n;
}

void insertAttail(node* &head, int val) {
	if (head == NULL) {
		insertAthead(head, val);
		return;
	}
	node* n = new node(val);
	node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = n;
	n->next = head;
}

void display(node* head) {
	node* temp = head;
	do {
		cout << temp->data << "->";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}


void deleteAthead(node* &head) {
	node* todelete = head;
	node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = head->next;
	head = temp->next;

	delete todelete;
}

void deletion(node* &head, int val) {
	if (head == NULL) {
		return;
	}

	if (head->data == val) {
		deleteAthead(head);
		return;
	}

	node* temp = head;
	while (temp->next->data != val) {
		temp = temp->next;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}


int main() {
	node* head = NULL;
	insertAttail(head, 1);
	insertAttail(head, 2);
	insertAttail(head, 3);
	insertAttail(head, 4);

	insertAthead(head, 9);
	display(head);

	deleteAthead(head);
	display(head);

	deletion(head, 3);
	display(head);



	return 0;
}

