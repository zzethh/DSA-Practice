// struct Node {
//     Node *zro, *one;
//     int cnt;

//     Node (int _cnt = 0, Node* _zro = nullptr, Node* _one = nullptr) :
//         cnt(_cnt), zro(_zro), one(_one) {}
// };


// struct Trie {
// public:

//     Trie () {
//         root = new Node(0);
//     }

//     void Insert (int x) {
//         Insert (x, 20, root);
//     }

//     void Remove (int x) {
//         Remove (x, 20, root);
//     }

//     int MaxXor (int x) {
//         return MaxXor (x, 20, root);
//     }

// private:

//     void Insert (int x, int bit, Node* root) {
//         root -> cnt ++;
//         if (bit < 0) return;

//         bool is_set = (x & (1 << bit)) > 0;
//         if (is_set) {
//             if (root -> one == nullptr) root -> one = new Node();
//             Insert (x, bit-1, root->one);
//         }
//         else {
//             if (root -> zro == nullptr) root -> zro = new Node();
//             Insert (x, bit-1, root->zro);
//         }
//     }

//     void Remove (int x, int bit, Node* root) {
//         root -> cnt --;
//         if (bit < 0) return;

//         bool is_set = (x & (1 << bit)) > 0;
//         if (is_set) Remove (x, bit-1, root -> one);
//         else Remove (x, bit-1, root -> zro);
//     }

//     int MaxXor (int x, int bit, Node* root) {
//         if (bit < 0) return 0;

//         bool is_set = (x & (1 << bit)) > 0;
//         if (is_set) {
//             if (root -> zro && root -> zro -> cnt > 0)
//                 return ((1 << bit) + MaxXor (x, bit-1, root -> zro));
//             else
//                 return MaxXor (x, bit-1, root -> one);
//         }
//         else {
//             if (root -> one && root -> one -> cnt > 0)
//                 return ((1 << bit) + MaxXor (x, bit-1, root -> one));
//             else
//                 return MaxXor (x, bit-1, root -> zro);
//         }
//     }

//     Node* root;
// };

class node {
public:
    node* links[2];
    int cnt1 = 0;
    int cnt0 = 0;
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    node* get(int bit) {
        return links[bit];
    }

    void put(int bit, node* n) {
        links[bit] = n;
    }
    void inc(int bit) {
        if (bit == 0) cnt0++;
        if (bit == 1) cnt1++;
    }
    void dec(int bit) {
        if (bit == 1) cnt1--;
        if (bit == 0) cnt0--;
    }
};
class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    void insert(int num) {
        node* n = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!n->containsKey(bit)) {
                n->put(bit, new node());
            }
            n = n->get(bit);
            n->inc(bit);
        }
    }
    int getmax(int num) {
        node* n = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (n->containsKey(1 - bit)) {
                maxnum = maxnum | (1 << i);
                n = n->get(1 - bit);
            }
            else {
                n = n->get(bit);
            }
        }
        return maxnum;
    }

    void remove(int num) {
        node* n = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (n->containsKey(bit)) {
                n = n->get(bit);
                n->dec(bit);
                if (n->cnt0 == 0) delete()
                }
            else return;
        }
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());

        int l = 0, r = -1;
        Trie trie;
        int ans = 0;

        while (l < n) {
            while (r + 1 < n && nums[r + 1] <= 2 * nums[l]) {
                r ++;
                trie.insert(nums[r]);
            }

            ans = max (ans, trie.getmax(nums[l]));

            trie.remove(nums[l]);
            l ++;
        }
        return ans;
    }
};