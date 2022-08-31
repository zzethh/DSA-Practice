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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nextN;
        int cnt = 1;

        while (current != NULL && cnt <= 2) {
            nextN = current->next;
            current->next = prev;
            prev = current;
            current = nextN;
            cnt++;
        }

        if (current != NULL) {
            head->next = swapPairs(current);
        }
        return prev;
    }
};