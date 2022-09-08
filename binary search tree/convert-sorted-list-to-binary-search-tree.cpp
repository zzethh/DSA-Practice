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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* convert1(vector<int> v, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* curr = new TreeNode(v[mid]);
        if (start == end) {
            return curr;
        }
        curr->left = convert1(v, start, mid - 1);
        curr->right = convert1(v, mid + 1, end);
        return curr;
    }

    vector<int> convert2(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        return v;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v = convert2(head);
        return convert1(v, 0, v.size() - 1);
    }
};