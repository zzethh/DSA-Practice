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
    ListNode* middle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == NULL) {
            return b;
        }
        if (b == NULL) {
            return a;
        }
        ListNode* c;
        if (a->val < b->val) {
            c = a;
            c->next = merge(a->next, b);
        }
        else {
            c = b;
            c->next = merge(a, b->next);
        }
        return c;

    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        ListNode* mid = middle(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;

        a = sortList(a);
        b = sortList(b);
        return merge(a, b);
    }
};