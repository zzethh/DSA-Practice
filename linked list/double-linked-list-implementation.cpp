#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* prev;
	node* next;

	node(int val) {
		data = val;
		prev = NULL;
		next = NULL;
	}
};

void insertAthead(node* &head, int val) {
	node* n = new node(val);
	n->next = head;
	if (head != NULL) {
		head->prev = n;
	}
	head = n;
}

void insertAttail(node* &head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		insertAthead(head, val);
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	n->prev = temp;
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


bool search(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void deleteAthead(node* &head) {
	node* todelete = head;
	head = head->next;
	head->prev = NULL;

	delete todelete;
}

void deletion(node* &head, int val) {
	if (head == NULL) {
		return;
	}

	if (head->next == NULL) {
		deleteAthead(head);
		return;
	}

	node* temp = head;
	while (temp != NULL && temp->data != val) {
		temp = temp->next;
	}
	node* todelete = temp;
	temp->prev->next = temp->next;

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}
	delete todelete;
}


int main() {
	node* head = NULL;
	insertAttail(head, 1);
	insertAttail(head, 2);
	insertAttail(head, 3);
	insertAttail(head, 4);

	insertAthead(head, 5);
	display(head);

	deletion(head, 3);
	display(head);

	deleteAthead(head);
	display(head);

	return 0;
}

