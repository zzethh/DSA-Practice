Node* merge(Node* a, Node* b) {
	if (a == NULL) return b;
	if (b == NULL) return a;
	Node* c;
	if (a->data < b->data) {
		c = a;
		c->bottom = merge(a->bottom, b);
	}
	else {
		c = b;
		c->bottom = merge(a, b->bottom);
	}
	return c;
}
Node* helper(Node* root) {
	if (root->next == NULL) {
		return root;
	}
	return merge(root, helper(root->next));
}
/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
	Node* temp = helper(root);
//   Node* temp2=temp;
//   while(temp!=NULL){
//       temp2->next=temp->bottom;
//       temp=temp->bottom;
//       temp2=temp2->next;
//   }
	//root->bottom=NULL;
	return temp;
}