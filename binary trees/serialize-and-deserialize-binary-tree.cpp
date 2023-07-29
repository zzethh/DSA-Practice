/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void helper(TreeNode* root, int level, map<int, vector<int>> &m) {
        if (root == NULL) {
            m[level].push_back(9999);
            return;
        }
        m[level].push_back(root->val);
        helper(root->left, level + 1, m);
        helper(root->right, level + 1, m);
    }
    string serialize(TreeNode* root) {
        map<int, vector<int>> m;
        helper(root, 0, m);
        string s = "";
        for (auto x : m) {
            vector<int> v = x.second;
            for (int i = 0; i < v.size(); i++) {
                int y = v[i];
                if (y == 9999) {
                    s += "# ";
                    continue;
                }
                s += to_string(y) + " ";
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return NULL;
        if (data[0] == '#') return NULL;

        stringstream ss(data);

        string token;
        vector<string> tokens;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }

        vector<int> v;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "#") {
                v.push_back(9999);
                continue;
            }
            int x = stoi(tokens[i]);
            v.push_back(x);
        }
        for (auto x : v) {
            cout << x << " ";
        }
        int i = 0;
        TreeNode* root = new TreeNode(v[i]);
        i++;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() and i < v.size()) {
            TreeNode* curr = q.front();
            q.pop();
            int c1 = v[i];
            i++;
            int c2 = v[i];
            i++;
            if (c1 != 9999) {
                curr->left = new TreeNode(c1);
                q.push(curr->left);
            }
            if (c2 != 9999) {
                curr->right = new TreeNode(c2);
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));