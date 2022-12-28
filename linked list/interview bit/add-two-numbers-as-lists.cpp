/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* temp1 = A;
    ListNode* temp2 = B;
    ListNode* n = new ListNode(-1);
    ListNode* temp = n;
    int carry = 0;
    while (temp1 != NULL or temp2 != NULL) {
        int a = 0;
        int b = 0;
        if (temp1 != NULL) a = temp1->val;
        if (temp2 != NULL) b = temp2->val;
        int sum = a + b + carry;
        ListNode* x = new ListNode(sum % 10);
        carry = sum / 10;
        temp->next = x;
        temp = temp->next;
        if (temp1 != NULL) temp1 = temp1->next;
        if (temp2 != NULL) temp2 = temp2->next;
    }
    if (carry) {
        ListNode* x = new ListNode(carry);
        temp->next = x;
    }
    ListNode* y = n;
    ListNode* todelete = y;
    n = n->next;
    delete todelete;
    return n;

}
