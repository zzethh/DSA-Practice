class FrequencyTracker {
public:
    //unordered_set<vector<int>> s;
    unordered_map<int, int> m;
    unordered_map<int, int> s;
    FrequencyTracker() {

    }

    void add(int number) {
        auto f = s.find(m[number]);
        if (f != s.end()) {
            s[m[number]]--;
            if (s[m[number]] == 0) s.erase(m[number]);
        }
        m[number]++;
        s[m[number]]++;

    }

    void deleteOne(int number) {
        auto f = m.find(number);
        if (f != m.end()) {
            if (m[number] >= 2) {
                s[m[number]]--;
                if (s[m[number]] == 0) s.erase(m[number]);
                m[number]--;
                s[m[number]]++;
            }
            else {
                s[m[number]]--;
                if (s[m[number]] == 0) s.erase(m[number]);
                m.erase(number);
            }
        }

    }

    bool hasFrequency(int frequency) {
        auto f = s.find(frequency);
        if (f != s.end()) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */