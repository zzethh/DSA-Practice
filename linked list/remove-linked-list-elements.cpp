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
    void deleteathead(ListNode* &head) {
        ListNode* todelete = head;
        head = head->next;
        delete todelete;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        if (head == NULL) {
            return NULL;
        }
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        if (head->val == val) {
            deleteathead(head);
        }

        return head;
    }
};