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
    ListNode* reverse(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* shead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return shead;
    }

    ListNode* mid(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

    }
    void reorderList(ListNode* head) {
        ListNode* midpoint = mid(head);
        ListNode* temp1 = head;
        ListNode* temp2 = reverse(midpoint->next);
        ListNode* temp3 = temp1;
        midpoint->next = NULL;
        bool flag = 1;
        temp1 = temp1->next;
        while (temp2 != NULL and temp1 != NULL) {
            if (flag) {
                temp3->next = temp2;
                temp2 = temp2->next;
            }
            else {
                temp3->next = temp1;
                temp1 = temp1->next;
            }

            flag = (!flag);
            temp3 = temp3->next;
        }

        if (temp1 != NULL) {
            temp3->next = temp1;
        }
        if (temp2 != NULL) {
            temp3->next = temp2;
        }
        head = temp3;
    }
};