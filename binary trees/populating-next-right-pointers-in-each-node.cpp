/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            Node* n = new Node(-1);
            Node* temp = n;
            while (q.front() != NULL) {
                cout << q.front()->val << " ";
                temp->next = q.front();
                temp = temp->next;
                if (q.front() != NULL and q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front() != NULL and q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
            }

            if (q.front() == NULL) {
                cout << NULL << "->";
                q.pop();
                if (q.empty()) {
                    cout << "empty" << endl;
                    return root;
                    cout << "return" << endl;
                }
                else {
                    q.push(NULL);
                    cout << "NULL inserted" << endl;
                }
            }
        }
        return root;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root) {
        if (root == NULL)
        {
            return;
        }

        if (root->left != NULL)
        {
            root->left->next = root->right;
        }
        if (root->next != NULL && root->right != NULL)
        {
            root->right->next = root->next->left;
        }

        helper(root->left);
        helper(root->right);
    }
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};