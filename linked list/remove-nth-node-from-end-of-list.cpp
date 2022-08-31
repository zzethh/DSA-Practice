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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        int pos = count - n ;
        int cnt = 0;
        ListNode* temp2 = head;
        if (pos == 0) {
            ListNode* todelete = head;
            head = head->next;
            delete todelete;
            return head;
        }
        while (temp2 != NULL && cnt != pos - 1) {
            temp2 = temp2->next;
            cnt++;
        }
        ListNode* todelete = temp2->next;
        temp2->next = temp2->next->next;
        delete todelete;
        return head;
    }
};