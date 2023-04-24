class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    int i = 0;
    RandomizedSet() {

    }

    bool insert(int val) {
        if (m.count(val)) return false;
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (m.count(val) == 0) return false;
        int idx = m[val];
        int f = v[v.size() - 1];
        swap(v[idx], v[v.size() - 1]);
        m[f] = idx;

        m.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom() {
        srand(i);
        i++;
        int r = rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */