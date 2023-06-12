class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        unordered_set<int> s;
        vector<int> indeg(n, 0);
        for (int i = 0; i < leftChild.size(); i++) {
            if (leftChild[i] != -1) {
                indeg[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                indeg[rightChild[i]]++;
            }
        }
        int root = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                root = i;
                cnt++;
            }
        }
        if (cnt != 1) return false;
        q.push(root);
        while (!q.empty()) {
            int f = q.front();
            //cout<<"hellp";
            cout << f << endl;
            q.pop();
            if (s.find(f) != s.end()) {
                return false;
            }
            s.insert(f);
            if (f<n and f >= 0 and leftChild[f] != -1) {
                q.push(leftChild[f]);
            }
            if (f<n and f >= 0 and rightChild[f] != -1) {
                q.push(rightChild[f]);
            }
        }
        return s.size() == n;
    }
}; s