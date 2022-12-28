/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* first = A;
    ListNode* second = first->next;
    if (second == NULL) return A;
    ListNode* future;
    ListNode* prev = NULL;
    while (first != NULL and second != NULL) {
        future = second->next;
        second->next = first;
        if (prev != NULL) {prev->next = second;}
        if (prev == NULL) A = second;
        prev = first;
        first = future;
        if (first != NULL) second = first->next;
    }
    prev->next = first;
    return A;
}
