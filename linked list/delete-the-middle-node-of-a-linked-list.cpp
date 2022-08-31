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
    int midpoint(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = 0;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            cnt++;
        }
        return cnt;
    }

    void deleteAthead(ListNode* &head) {
        ListNode* todelete = head;
        head = head->next;
        delete todelete;
    }

    void deletion(ListNode* &head, int pos) {
        ListNode* temp = head;
        if (temp->next == NULL) {
            deleteAthead(head);
            return;
        }
        int cnt = 0;
        while (temp != NULL and cnt != pos - 1) {
            temp = temp->next;
            cnt++;
        }
        ListNode* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }

    ListNode* deleteMiddle(ListNode* head) {
        int mid = midpoint(head);
        deletion(head, mid);
        return head;
    }
};