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
    int count(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = count(head);
        if (n == 0) return head;
        int pos = n - (k % n);
        int cnt = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        ListNode* temp2 = head;
        while (cnt < pos) {
            temp2 = temp2->next;
            cnt++;
        }
        head = temp2->next;
        temp2->next = NULL;
        return head;
    }
};