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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }
        ListNode* temp1 = head;
        int cnt1 = 0;
        while (temp1 != NULL and cnt1 != k - 1) {
            temp1 = temp1->next;
            cnt1++;
        }
        ListNode* temp2 = head;
        int cnt2 = 0;
        while (temp2 != NULL and cnt2 != (n - k)) {
            temp2 = temp2->next;
            cnt2++;
        }

        swap(temp1->val, temp2->val);
        return head;

    }
};