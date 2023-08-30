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
    Trie() {
        root = new node();
    }

    void insert(string word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (!n->containsKey(word[i])) {
                n->put(word[i], new node());
            }
            n = n->get(word[i]);
        }
        n->setend();
    }

    bool search(string word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (n->containsKey(word[i])) {
                n = n->get(word[i]);
            }
            else return false;
        }
        if (n->flag) return true;
        return false;
    }

    bool startsWith(string word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (n->containsKey(word[i])) {
                n = n->get(word[i]);
            }
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */