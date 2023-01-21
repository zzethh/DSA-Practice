/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

void deleteAthead(ListNode* &head) {
    ListNode* todelete = head;
    head = head->next;

    delete todelete;
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != NULL) {
            ListNode* temp = A[i];
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
