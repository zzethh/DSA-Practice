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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        stack<int> ans;
        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!s1.empty() or !s2.empty()) {
            int a = 0, b = 0;
            if (!s1.empty()) {
                a = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                b = s2.top();
                s2.pop();
            }
            int sum = a + b + carry;
            ans.push(sum % 10);
            //ListNode* n=new ListNode(sum%10);
            carry = sum / 10;
            //temp->next=n;
            // temp=temp->next;
        }
        if (carry) {
            ans.push(carry);
        }
        while (!ans.empty()) {
            ListNode* n = new ListNode(ans.top());
            ans.pop();
            temp->next = n;
            temp = temp->next;
        }
        return dummy->next;
    }
};