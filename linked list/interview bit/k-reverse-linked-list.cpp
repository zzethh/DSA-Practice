/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if (A == NULL) {
        return NULL;
    }
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* temp;
    int cnt = 1;
    while (curr != NULL and cnt <= B) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    if (temp != NULL) A->next = reverseList(temp, B);
    return prev;
}
