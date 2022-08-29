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


node* merge(node* a, node* b) {
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}
	node* c ;
	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	} else {
		c = b;
		c->next = merge(a, b->next);
	}

	return c;
}

node* midpoint(node* head) {
	node* temp = head->next;
	node* slow = head;
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next->next;
		slow = slow->next;
	}
	return slow;
}

node* mergeSort(node* head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* mid = midpoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a, b);
}

int main() {
	node* head = NULL;
	insertAthead(head, 1);
	insertAthead(head, 7);
	insertAthead(head, 8);
	insertAthead(head, 0);

	display(head);

	node* x = mergeSort(head);
	display(x);






	return 0;
}

