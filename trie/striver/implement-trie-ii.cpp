#include <bits/stdc++.h>
class node {
public:
    node* links[26];
    int cnte = 0;
    int cntp = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, node* n) {
        links[ch - 'a'] = n;
    }

    void increaseEnd() {
        cnte++;
    }

    void increasePre() {
        cntp++;
    }

    void deleteEnd() {
        cnte--;
    }
    void reducePre() {
        cntp--;
    }
};
class Trie {

public:
    node* root;
    Trie() {
        root = new node;
    }

    void insert(string &word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (!n->containsKey(word[i])) {
                n->put(word[i], new node());
            }
            n = n->get(word[i]);
            n->increasePre();
        }
        n->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (!n->containsKey(word[i])) {
                return 0;
            }
            n = n->get(word[i]);
        }
        return n->cnte;
    }

    int countWordsStartingWith(string &word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (!n->containsKey(word[i])) {
                return 0;
            }
            n = n->get(word[i]);
        }
        return n->cntp;
    }

    void erase(string &word) {
        node* n = root;
        for (int i = 0; i < word.length(); i++) {
            if (n->containsKey(word[i])) {
                n = n->get(word[i]);
                n->reducePre();
            }
            else return;
        }
        n->deleteEnd();
    }
};
