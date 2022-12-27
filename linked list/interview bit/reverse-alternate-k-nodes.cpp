/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* help(ListNode* &A, int B, bool flag) {
    if (A == NULL) return NULL;
    if (flag == 0) {
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
        if (temp != NULL) A->next = help(temp, B, 1);
        return prev;
    }
    flag = !flag;
    ListNode* temp = A;
    ListNode* head = temp;
    int cnt = 1;
    while (temp != NULL and cnt < B) {
        temp = temp->next;
        cnt++;
    }
    if (temp != NULL) temp->next = help(temp->next, B, 0);
    return head;
}

ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* ans = help(A, B, 0);
    return ans;
}
