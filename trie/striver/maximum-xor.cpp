class node {
public:
    node* links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    node* get(int bit) {
        return links[bit];
    }

    void put(int bit, node* n) {
        links[bit] = n;
    }
};
class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    int insert(int num) {
        node* n = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!n->containsKey(bit)) {
                n->put(bit, new node());
            }
            n = n->get(bit);
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
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie t;
    for (auto it : arr1) t.insert(it);
    int maxi = 0;
    for (auto it : arr2) {
        maxi = max(maxi, t.getmax(it));
    }
    return maxi;
}