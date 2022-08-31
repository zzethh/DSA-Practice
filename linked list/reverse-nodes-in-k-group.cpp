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
    int count(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nextN;
        int cnt = 1;

        if (count(head) < k) {
            return head;
        }

        while (current != NULL && cnt <= k) {
            nextN = current->next;
            current->next = prev;
            prev = current;
            current = nextN;
            cnt++;
        }

        if (current != NULL) {
            head->next = reverseKGroup(current, k);
        }
        return prev;
    }
};