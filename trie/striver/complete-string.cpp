#include <bits/stdc++.h>
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

    bool check(string word) {
        // node *n = root;
        // bool flag = true;
        // for(int i = 0;i<word.size();i++) {
        //     if(n->containsKey(word[i])) {
        //         n = n->get(word[i]);
        //         flag = flag & n->flag;
        //     }
        //     else {
        //         return false;
        //     }
        // }
        // return flag;
        node* n = root;
        for (int i = 0; i < word.size(); i++) {
            if (!n->containsKey(word[i])) {
                return false;
            }
            n = n->get(word[i]);
            if (n->flag == false) return false;
        }
        if (n->flag == false) return false;
        return true;
    }

};
string completeString(int n, vector<string> &a) {
    Trie* t = new Trie();
    for (auto it : a) {
        t->insert(it);
    }

    string longest = "";
    for (auto it : a) {
        if (t->check(it)) {
            if (it.length() > longest.length()) {
                longest = it;
            }
            else if (it.length() == longest.length() and it < longest) {
                longest = it;
            }
        }
    }

    if (longest == "") return "None";
    return longest;
}