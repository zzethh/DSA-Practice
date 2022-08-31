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
    void deleteAthead(ListNode* &head) {
        ListNode* todelete = head;
        head = head->next;

        delete todelete;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* current = head;
        ListNode* ans = new ListNode(-1);
        ListNode* prev = ans;
        prev->next = head;

        while (current != NULL) {
            if (current->next != NULL and current->val == current->next->val) {
                while (current->next != NULL and current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                prev = prev->next;
            }
            current = current->next;
        }
        deleteAthead(ans);
        return ans;
    }
};