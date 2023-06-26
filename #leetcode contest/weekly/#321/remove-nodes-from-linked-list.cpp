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
    ListNode* removeNodes(ListNode* head) {
        vector<vector<int>> t;
        ListNode* temp = head;
        int i = 0;
        while (temp != NULL) {
            t.push_back({temp->val, i});
            temp = temp->next;
            i++;
        }
        //cout<<i;
        vector<int> v(i, -1);
        stack<int> st;
        for (int j = i - 1; j >= 0; j--) {
            while (!st.empty() and st.top() <= t[j][0]) {
                st.pop();
            }
            if (!st.empty()) v[j] = st.top();
            st.push(t[j][0]);
        }
        // for(auto x:v){
        //     cout<<x<<" ";
        // }
        unordered_set<int> s;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                s.insert(t[i][1]);
            }
        }
        temp = head;
        int cnt = 0;
        bool flag = true;
        ListNode* prev = head;
        while (temp != NULL) {
            if (s.find(cnt) != s.end()) {
                if (flag) {
                    head = temp;
                    prev = temp;
                    flag = false;
                }
                else {
                    prev->next = temp;
                    prev = temp;
                }
            }
            cnt++;
            temp = temp->next;
        }
        return head;
    }
};