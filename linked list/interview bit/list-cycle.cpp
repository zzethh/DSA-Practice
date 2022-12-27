/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* returnNode(ListNode* A) {
	ListNode* fast = A;
	ListNode* slow = A;
	do {
		fast = fast->next->next;
		slow = slow->next;
	} while (fast != slow);
	fast = A;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

bool containCycle(ListNode* A) {
	ListNode* fast = A;
	ListNode* slow = A;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}

ListNode* Solution::detectCycle(ListNode* A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if (containCycle(A)) return returnNode(A);
	return NULL;
}
