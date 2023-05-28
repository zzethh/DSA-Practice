/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right == left) return head;
        ListNode* l = head;
        ListNode* ll = NULL;
        int n = 0;
        ListNode* x = head;
        while (x != NULL) {
            x = x->next;
            n++;
        }
        int pos = 0;
        while (l != NULL and pos != left - 1) {
            ll = l;
            l = l->next;
            pos++;
        }
        ListNode* prev = NULL;
        ListNode* curr = l;
        ListNode* temp;
        int k = 0;
        while (curr != NULL and k != right - left + 1) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k++;
        }
        if (ll != NULL) ll->next = prev;
        if (l != NULL) l->next = temp;
        if (right == n and left == 1) return prev;
        if (left == 1) return prev;
        return head;
    }
};