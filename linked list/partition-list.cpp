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

    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> small;
        queue<ListNode*> high;
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val < x) {
                small.push(temp);
            } else {
                high.push(temp);
            }
            temp = temp->next;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* t = ans;
        while (!small.empty()) {
            t->next = small.front();
            t = t->next;
            small.pop();
        }
        while (!high.empty()) {
            t->next = high.front();
            t = t->next;
            high.pop();
        }
        t->next = NULL;
        deleteAthead(ans);
        return ans;
    }
};