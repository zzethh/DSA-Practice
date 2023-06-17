class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_set<char> s1;
        unordered_set<char> s2;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for (auto x : word1) {
            s1.insert(x);
            m1[x]++;
        }
        for (auto x : word2) {
            s2.insert(x);
            m2[x]++;
        }
        if (s1.size() == s2.size() and word1.length() == word2.length()) return true;
        int s = 'a';
        for (int i = s; i < s + 26; i++) {
            char t = char(i);
            if (s1.find(t) == s1.end()) continue;
            for (int j = s; j < s + 26; j++) {
                char c = char(j);
                //if(t==c) continue;
                if (s2.find(c) == s2.end()) continue;
                //insert c and delete t
                m1[t]--;
                if (m1[t] <= 0) s1.erase(t);
                m1[c]++;
                s1.insert(c);

                //insert t and delete c
                m2[c]--;
                if (m2[c] <= 0) s2.erase(c);
                m2[t]++;
                s2.insert(t);

                if (s1.size() == s2.size()) return true;

                m1[t]++;
                s1.insert(t);
                m1[c]--;
                if (m1[c] <= 0) s1.erase(c);

                m2[c]++;
                s2.insert(c);
                m2[t]--;
                if (m2[t] <= 0) s2.erase(t);
            }
            //cout<<endl;
        }

        return false;

    }
};