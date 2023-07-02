/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if (head == NULL)return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return slow;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if (hasCycle(head) == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = hasCycle(head);
        if (slow == head) return head;
        while (fast->next != slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast->next;
    }
};