/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    int ptr = 0;
    ListNode* x = A;
    while (x != NULL) {
        x = x->next;
        ptr++;
    }

    if (ptr == 1) return A;

    if (ptr == 2) {
        ListNode* head = A;
        ListNode* nxt = head->next;
        head->next = NULL;
        nxt->next = head;
        return A;
    }

    ListNode* temp = A;
    ListNode* ahead = NULL;
    int cnt = 1;
    ListNode* last = NULL;
    ListNode* next;
    ListNode* head;
    ListNode* current;
    ListNode* prev = NULL;
    while (temp != NULL and cnt <= C + 1) {
        if (cnt == B - 1) {
            last = temp;
            prev = temp;
        }
        if (cnt == B) {
            head = temp;
            current = temp;
        }
        if (cnt == C + 1) ahead = temp;
        temp = temp->next;
        cnt++;
    }

    ListNode* temp2;
    while (current != ahead) {
        temp2 = current->next;
        current->next = prev;
        prev = current;
        current = temp2;
    }
    if (last != NULL) last->next = prev;
    else if (last == NULL) A = prev;
    head->next = temp2;
    return A;
}
