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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        ListNode* temp2 = head;
        cnt--;
        int sum = 0;
        while (temp2 != NULL) {
            sum = sum + (temp2->val) * pow(2, cnt);
            cnt--;
            temp2 = temp2->next;
        }
        return sum;
    }
};