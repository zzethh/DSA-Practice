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

    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* x = new ListNode(-1);
        ListNode* start = x;
        int sum = 0;
        while (temp != NULL) {
            int sum = sum + temp->val;
            if (temp->val == 0) {
                ListNode* n = new ListNode(sum);
                x->next = n;
                x = x->next;
                sum = 0;
            }
            temp = temp->next;
        }
        deleteAthead(start);
        deleteAthead(start);
        return start;
    }
};