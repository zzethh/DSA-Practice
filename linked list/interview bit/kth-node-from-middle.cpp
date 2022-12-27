/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode* temp = A;
    int n = 0;
    while (temp != NULL) {
        temp = temp->next;
        n++;
    }

    int pos = (n / 2) + 1 - B;
    ListNode* temp2 = A;
    int cnt = 1;
    if (pos <= 0) return -1;
    while (temp2 != NULL and cnt < pos) {
        temp2 = temp2->next;
        cnt++;
    }
    return temp2->val;
}
