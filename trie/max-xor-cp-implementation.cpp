struct Node {
    Node *zro, *one;
    int cnt;

    Node (int _cnt = 0, Node* _zro = nullptr, Node* _one = nullptr) : 
        cnt(_cnt), zro(_zro), one(_one) {} 
};


struct Trie {
public:
    
    Trie () {
        root = new Node(0);
    }
    
    void Insert (int x) {
        Insert (x, 20, root);
    }
    
    void Remove (int x) {
        Remove (x, 20, root);
    }
    
    int MaxXor (int x) {
        return MaxXor (x, 20, root);
    }
    
private:
    
    void Insert (int x, int bit, Node* root) {
        root -> cnt ++;
        if (bit < 0) return;
        
        bool is_set = (x & (1 << bit)) > 0;
        if (is_set) {
            if (root -> one == nullptr) root -> one = new Node();
            Insert (x, bit-1, root->one);
        }  
        else {
            if (root -> zro == nullptr) root -> zro = new Node();
            Insert (x, bit-1, root->zro);
        }
    }
    
    void Remove (int x, int bit, Node* root) {
        root -> cnt --;
        if (bit < 0) return;
        
        bool is_set = (x & (1 << bit)) > 0;
        if (is_set) Remove (x, bit-1, root -> one);
        else Remove (x, bit-1, root -> zro);
    }
    
    int MaxXor (int x, int bit, Node* root) {
        if (bit < 0) return 0;
        
        bool is_set = (x & (1 << bit)) > 0;
        if (is_set) {
            if (root -> zro && root -> zro -> cnt > 0) 
                return ((1 << bit) + MaxXor (x, bit-1, root -> zro));
            else 
                return MaxXor (x, bit-1, root -> one);
        }
        else {
            if (root -> one && root -> one -> cnt > 0) 
                return ((1 << bit) + MaxXor (x, bit-1, root -> one));
            else 
                return MaxXor (x, bit-1, root -> zro);
        }
    }
    
    Node* root;
};