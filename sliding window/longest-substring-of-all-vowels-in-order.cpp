class Solution {
public:
    char assign(char ch) {
        if (ch == 'a') {
            return 'e';
        }
        if (ch == 'e') {
            return 'i';
        }
        if (ch == 'i') {
            return 'o';
        }
        return 'u';
    }
    int longestBeautifulSubstring(string word) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        vector<bool> mp(26, 0);
        vector<bool> mp2(26, 0);
        for (auto x : v) {
            mp[x - 'a'] = 1;
        }
        int len = 0;
        char next = 'a';
        char prev = 'a';
        int j = 0;
        for (int i = 0; i < word.size(); i++) {
            mp2[word[i] - 'a'] = 1;
            if (word[i] == prev or word[i] == next) {
                if (mp2 == mp) {
                    cout << j << " " << i << endl;
                    len = max(len, i - j + 1);
                }
            }
            else {
                mp2.clear();
                mp2.resize(26, 0);
                //mp2[word[i]-'a']=1;
                if (word[i] == 'a') {
                    mp2[word[i] - 'a'] = 1;
                    j = i;
                    prev = 'a';
                    next = 'e';
                    continue;
                }
                else j = i + 1;
                next = 'a';
                prev = 'a';
                continue;
            }
            prev = word[i];
            next = assign(word[i]);
        }
        return len;
    }
};