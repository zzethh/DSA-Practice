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
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev = head;
        while (temp != NULL) {
            //cout<<temp->val<<" ";
            int x = gcd(temp->val, prev->val);
            ListNode* n = new ListNode(x);
            n->next = temp;
            prev->next = n;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};