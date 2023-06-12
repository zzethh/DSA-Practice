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
    void search(int target, TreeNode* root, vector<TreeNode*> &v) {
        if (root == NULL) return;
        if (root->val == target) {
            v.push_back(root);
        }
        search(target, root->left, v);
        search(target, root->right, v);
    }
    bool helper(ListNode* head, TreeNode* root) {
        if (head->next == NULL and head->val == root->val) return true;
        if (root->val != head->val) {
            return false;
        }
        bool left = false;
        bool right = false;
        if (root->left and head->next and head->next->val == root->left->val) {
            left = helper(head->next, root->left);
        }
        if (root->right and head->next and head->next->val == root->right->val) {
            right = helper(head->next, root->right);
        }

        if (left or right) {
            return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> v;
        search(head->val, root, v);
        for (auto x : v) {
            if (helper(head, x)) {
                return true;
            }
        }
        return false;
    }
};