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
    int pairSum(ListNode* head) {
        deque<int> d;
        ListNode* temp = head;
        while (temp != NULL) {
            d.push_back(temp->val);
            temp = temp->next;
        }

        int maxi = INT_MIN;
        while (!d.empty()) {
            int sum = d.front() + d.back();
            d.pop_front();
            d.pop_back();
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};