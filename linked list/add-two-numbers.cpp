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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* c = new ListNode(-1);
        ListNode* temp = c;
        int carry = 0;
        while (a != NULL or b != NULL) {
            int dig1 = 0;
            int dig2 = 0;
            if (a == NULL) {
                dig2 = b->val;
            }
            else if (b == NULL) {
                dig1 = a->val;
            }
            else {
                dig1 = a->val;
                dig2 = b->val;
            }
            int sum = dig1 + dig2 + carry;
            int sumtoadd = sum % 10;
            ListNode* n = new ListNode(sumtoadd);
            carry = sum / 10;
            temp->next = n;
            temp = temp->next;
            if (a != NULL) {
                a = a->next;
            }
            if (b != NULL) {
                b = b->next;
            }
        }
        if (carry > 0) {
            ListNode* x = new ListNode(carry);
            temp->next = x;
        }
        deleteAthead(c);
        return c;
    }
};