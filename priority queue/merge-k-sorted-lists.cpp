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

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:

    void deleteAthead(ListNode* &head) {
        ListNode* todelete = head;
        head = head->next;

        delete todelete;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                ListNode* temp = lists[i];
                pq.push(temp);
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* c = ans;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            c->next = temp;
            c = c->next;
            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }
        deleteAthead(ans);
        return ans;
    }
};