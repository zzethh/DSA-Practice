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
    ListNode* reverseList(ListNode* &head) {
        ListNode* current = head;
        ListNode* nxt;
        ListNode* prev = NULL;
        while (current != NULL) {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }

    ListNode* midpoint(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = midpoint(head)->next;
        ListNode* reverse = reverseList(mid);
        while (reverse != NULL) {
            if (reverse->val != head->val) {
                return false;
            }
            reverse = reverse->next;
            head = head->next;

        }

        return true;
    }
};