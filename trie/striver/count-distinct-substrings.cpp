class node {
public:
    node *links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, node* n) {
        links[ch - 'a'] = n;
    }

    node* get(char ch) {
        return links[ch - 'a'];
    }

    void setend() {
        flag = true;
    }
};

class Trie {
public:
    node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    int insert(string word) {
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            node* n = root;
            for (int j = i; j < word.size(); j++) {
                if (!n->containsKey(word[j])) {
                    cnt++;
                    n->put(word[j], new node());
                }
                n = n->get(word[j]);
            }
        }
        return cnt;
    }
};
int countDistinctSubstrings(string &s)
{
    Trie t;
    return t.insert(s) + 1;
}