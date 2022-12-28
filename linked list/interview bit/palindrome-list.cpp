/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* temp;
    ListNode* prev = NULL;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {

    ListNode* slow = A;
    ListNode* fast = A;
    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* temp2 = reverse(slow);
    ListNode* temp1 = A;
    while (temp2 != NULL and temp1 != NULL) {
        if (temp1->val != temp2->val) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return true;
}
