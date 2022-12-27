/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* temp = A;
    int cntz = 0;
    int cnto = 0;
    while (temp != NULL) {
        if (temp->val == 0) {
            cntz++;
        }
        else cnto++;
        temp = temp->next;
    }
    ListNode* x = A;
    while (x != NULL) {
        if (cntz) {
            x->val = 0;
            cntz--;
        }
        else {
            x->val = 1;
            cnto--;
        }
        x = x->next;
    }
    return A;
}
